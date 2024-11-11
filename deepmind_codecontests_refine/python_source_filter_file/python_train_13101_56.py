import collections
N,C,K=map(int,input().split())
T=[int(input()) for i in range(N)]
T.sort()

count=1
cus=0
pre=T[0]
for t in T:
    if C>cus and pre+K>t:
        cus+=1
    else:
        cus=1
        pre=t
        count+=1
print(count)
