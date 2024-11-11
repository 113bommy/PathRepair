import sys, os.path
from collections import*
from heapq import *
from copy import*
import math
mod=10**9+7
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")   
 
s=input()
n=len(s)
print('L',2)
print('R',2)
print('R',2*n-1)