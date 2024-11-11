# -*- coding: utf-8 -*-
"""
Created on Sat Jan 19 01:42:31 2019

@author: KIIT
"""

import math
import os
import random
import re
import sys
if __name__ == '__main__':
    x = list(map(int, input().rstrip().split()))
    a,b,c=x[0],x[1],x[2]
    
    if(c==0):
        if((b-a)==0):
            print("YES")
        else:
            print("NO")
    else:
        k=(b-a)%c
        if(k==0 and (b-a)/c>0):
            print("YES")
        else:
            print("NO")