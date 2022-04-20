#!/bin/bash

if (g++ bookshop.cpp bs_main.cpp -o bs.out && ./bs.out)
then
  echo "----------------------"
  echo "Tests SUCCESSFUL"
else
  echo "----------------------"
  echo "Tests FAILED"
fi