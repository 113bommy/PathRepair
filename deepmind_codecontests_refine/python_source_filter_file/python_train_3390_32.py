#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the function below.
m=input().split()
row= m[0]
col= m[1]

s=''
i=0
while i<int(row):
    s=s+ str(input())
    i=i+1

s=s.replace(" ",'')
s=s.replace("B",'')
s=s.replace("W",'')
s=s.replace("G",'')

if len(s)==0:
    print("#Black&White")
else:
    print("Color")