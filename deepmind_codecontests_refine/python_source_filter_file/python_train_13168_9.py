import sys
import os
def getint():
    return list(map(int,input().split(' ')))
n,s=getint()
dic={'B':{},'S':{}}
for i in range(n):
    d,p,q=list(input().split(' '))
    p=int(p)
    q=int(q)
    dic[d][p]=dic[d].get(p,0)+q
for key in sorted(dic['S'],reverse=True)[:s]:
    print('S',key,dic['S'][key])
for key in sorted(dic['B'],reverse=True)[:s]:
    print('B',key,dic['B'][key])
    #for line in sorted(dic['B'])[:s]:
        #print('B',line)
