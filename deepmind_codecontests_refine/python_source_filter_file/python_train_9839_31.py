m=int(input())
k=[]
import math
while m>0:
    k=k+[int(input())]
    m=m-1
s=[]
while m<len(k):
    n=k[m]
    sq=(1+n)*n/2
    i=int()
    while 2**i<=n:
        sq=int(sq-2*(2**i))
        i=i+1
    s=s+[sq]
    m=m+1
m=0
while m<len(s):
    print(s[m])
    m=m+1
