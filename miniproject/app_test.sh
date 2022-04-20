#!/bin/bash

if (g++ bookshop.cpp bs_test.cpp -o bs.out && ./bs.out)
then
  echo "----------------------"
  echo "Tests SUCCESSFUL"
else
  echo "----------------------"
  echo "Tests FAILED"
fi