#!/bin/bash
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:build-CalculatorOperationsLib-Desktop_Qt_5_12_12_GCC_64bit-Release
export LD_LIBRARY_PATH
chmod ugo+x build-InteltehCalculator-Desktop_Qt_5_12_12_GCC_64bit-Release/InteltehCalculator
echo "Приложение калькулятор запускается..."
./build-InteltehCalculator-Desktop_Qt_5_12_12_GCC_64bit-Release/InteltehCalculator
