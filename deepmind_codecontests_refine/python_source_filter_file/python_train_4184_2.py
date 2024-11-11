# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
from sys import stdin, stdout
from itertools import accumulate

#T = int(input())
s = input()
#N,M,K,Q = [int(x) for x in stdin.readline().split()]
#arr = [int(x) for x in stdin.readline().split()]

def computeGCD(x, y):

   while(y):
       x, y = y, x % y

   return x

record = {}

for x in range(10):
    for y in range(10):
        for d in range(10):
            m = 9999
            if x==0 and y==0 and d==0:
                record[(x,y,d)] = 0
            elif x==0 and y==0 and d!=0:
                record[(x,y,d)] = -1
            else:
                for k in range(10):
                    d_tmp = d + 10*k
                    if x==0:
                        if d_tmp%y==0:
                            record[(x,y,d)] = d_tmp//y - 1
                            break

                    elif y==0:
                        if d_tmp%x==0:
                            record[(x,y,d)] = d_tmp//x - 1
                            break

                    else:
                        for a in range((d_tmp//x)+1):
                            for b in range((d_tmp//y)+1):
                                if x*a+y*b==d_tmp and d_tmp!=0:
                                    m = min(m,a+b-1)

                if (x,y,d) not in record:
                    if m==9999:
                        m = -1
                    record[(x,y,d)] = m
            #print(x,y,d,record[(x,y,d)])

data = [[0]*10 for _ in range(10)]

len_s = len(s)
s = list(s)
freq = [0]*10
for i in range(len_s-1):
    A = s[i]
    B = s[i+1]

    d = ord(B)-ord(A)
    if d<0:
        d += 10

    freq[d] += 1

for x in range(10):
    for y in range(10):
        for d in range(10):
            if freq[d]==0:
                data[x][y] += 0
            elif record[(x,y,d)]==-1:
                data[x][y] = -10000000
            else:
                data[x][y] += freq[d]*record[(x,y,d)]

for x in range(10):
    for y in range(10):
        if data[x][y]<0:
            print(-1,end=' ')
        else:
            print(data[x][y],end=' ')
    print('',end='\n')
