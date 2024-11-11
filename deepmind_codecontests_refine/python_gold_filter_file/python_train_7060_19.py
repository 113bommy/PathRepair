from collections import deque
N=int(input())
A=[int(i) for i in input().split()]
A=[0]+A
for i in range(N):
    A[i+1]+=A[i]
def dou(i,j):
    ma=j
    mi=i
    while ma-mi>1:
        mid = (ma + mi)//2
        a=A[j]-A[mid]
        b=A[mid-1]-A[i]
        if a>b:
            mi=mid
        else:
            ma=mid
        #print(ma,mi)
    return [A[mi]-A[i],A[j]-A[mi]]
num=10**14
for i in range(2,N-1):
    ans=[]
    ans+=dou(0,i)
    ans+=dou(i,N)
    #print(ans)
    t=max(ans)-min(ans)
    num=min(num,t)
print(num)