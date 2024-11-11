#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the function below.


def function(a):
    tot= sum(a)
    if tot%2==0:
        print(tot//2)
    else:
        tot=tot-1
        print(tot//2) 



count=int(input())
i=0
while i!=count:
   a=[int(x) for x in input().split()]
   function(a)
   i=i+1