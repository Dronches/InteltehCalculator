#include "threadcomputationcollections.h"

ThreadComputationCollections::ThreadComputationCollections(std::shared_ptr<CollectionsContainer> collectionContainer)
{
    this->collectionContainer = collectionContainer;
}

bool ThreadComputationCollections::PerformDoIt()
{
   // Извлечь операцию из начала очереди
   OperationInfo * operation = collectionContainer->PopOperation();
   if (!operation)
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
               operation->GetTypeOperation(),
               operation->GetleftOperand(),
               operation->GetRightOperand(),
               errorComputations);
   // Выполнение ожидания оставшегося времени в миллисекундах
   timer.WaitForStopTimer(operation->GetOperationTime()*1000);
   // добавление результата в конец очереди
   collectionContainer->PushResult(operation, *errorComputations, result);

   delete errorComputations;
   return true;
}
