#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      Yushant Tyagi
#
# Created:     20-12-2019
# Copyright:   (c) Yushant Tyagi 2019
# Licence:     <your licence>
#-------------------------------------------------------------------------------

for _ in range(int(input())):
    a,b=map(int,input().split())
    if(a==b):
        print(0)
        continue
    if(a>b):
        f=a
        a=b
        b=f
    i=1
    d=b-a
    an=0
    while(1):
        an+=i
        if(an>=d and (an-d)%2==0):
            break
        i+=1
    print(i)
