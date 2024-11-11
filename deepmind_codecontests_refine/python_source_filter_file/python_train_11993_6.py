import time
import sys
input = sys.stdin.buffer.readline


ddd = 10**9+7
s= list(input())
# print(s)
# s='u'*99999
prev = s[0]
flists=[]
ucount =0
ncount =0
i=0
if 109 in s or 119 in s:
    print(0)
else:
    while i<len(s):
        while( i<len(s)and s[i]==117 ):
            ucount+=1
            i+=1
        if (ucount):
            # print(ucount)
            flists.append(ucount)
            ucount=0
        while( i <len(s) and s[i]==110):
            ncount+=1
            i+=1
        if(ncount):
            flists.append(ncount)
            # print(ncount)
            ncount=0
        # print(i)
        while(i<len(s) and s[i] not in [117 , 110]):
            i+=1
    # print(flists)
    if len(flists)==0:
        print (1)
    else:
        x=[0]*(max(flists)+1)
        # x=[0]*99999

        x[0] = 1
        x[1] = 1
        t1= time.time()
        for i in range(2,len(x)):
            x[i] = (x[i-1]+x[i-2])%(ddd)
        t2= time.time()
        # print(t2-t1)
        rem = 1
        for i in flists:
            rem = (rem*x[i])%ddd
        print(rem)
        print(x[-1])