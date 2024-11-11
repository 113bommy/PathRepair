import sys
n=int(input())
pr=[1,2,3,5,7,11]
for i in range(n):
    k=int(input())
    if k in pr:
        print(-1)
        continue
    if k%2==0:print(k//4)
    else:print((k-9)//4+1)