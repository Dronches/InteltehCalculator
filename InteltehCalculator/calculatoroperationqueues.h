#ifndef CALCULATOROPERATIONQUEUES_H
#define CALCULATOROPERATIONQUEUES_H

#include <QObject>
#include <calculatoroperationslib.h>

/*!
 * \brief Класс, организующий сохранение операции и текущего времени операции
 * TODO: использование в качестве адаптера относительно класса-контейнера очередей
 * Предполагается, что данный класс в дальнейшем может использовать механизм Signal-Slot
 */
class CalculatorOperationQueues : public QObject
{
    Q_OBJECT

    /// Текущий тип операции
    CalculatorOperationsLib::TypesOperation currentOperation;
    /// Текущее врема операции (в секундах)
    int currentOperationTime;


public:

    explicit CalculatorOperationQueues(QObject *parent = nullptr);

    /*!
     * \brief Получить значение текущей операции
     * \return Значение текущей операции
     */
    CalculatorOperationsLib::TypesOperation GetCurrentOperation();

    /*!
     * \brief Получить значение текущего времени операции
     * \return Значение текущего времени операции
     */
    int GetCurrentOperationTime();

    /*!
     * \brief Установить значение текущей операции
     * \param operation операция
     */
    void SetCurrentOperation(CalculatorOperationsLib::TypesOperation operation);

    /*!
     * \brief Установить значение текущего времени операции
     * \param time время операция
     */
    void SetCurrentOperationTime(int time);


signals:

};

#endif // CALCULATOROPERATIONQUEUES_H
