#include "threadcomputationcollections.h"

ThreadComputationCollections::ThreadComputationCollections(std::shared_ptr<CollectionsContainer> collectionContainer)
{
    this->collectionContainer = collectionContainer;
}

bool ThreadComputationCollections::PerformDoIt()
{
   // Извлечь операцию из начала очереди
   RequestInfo * requestInfo = collectionContainer->PopRequest();
   if (!requestInfo)
   {
       // Пассивное ожидание (для того, чтобы не нагружать потоком процессор)
       timer.ThreadSleep();
       return false;
   }
   CalculatorOperationsLib::TypesComputationErrors* errorComputations =
           new CalculatorOperationsLib::TypesComputationErrors(
               CalculatorOperationsLib::TypesComputationErrors::NoComputationError
               );
   // запуск тамймера
   timer.StartTimer();
   // выполнение операции
   double result = CalculatorOperationsLib::DoIt(
               requestInfo->GetTypeOperation(),
               requestInfo->GetleftOperand(),
               requestInfo->GetRightOperand(),
               errorComputations);
   // Выполнение ожидания оставшегося времени в миллисекундах
   timer.WaitForStopTimer(requestInfo->GetOperationTime()*1000);
   // добавление результата в конец очереди
   collectionContainer->PushResult(requestInfo, *errorComputations, result);

   delete errorComputations;
   return true;
}
