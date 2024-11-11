'''Author- Akshit Monga'''
import sys
n=int(input())
arr=[]
for i in range(n):
    arr.append(input())
ans=float('inf')
for i in arr:
    star=i
    p=0
    for j in arr:
        temp=j
        if temp==star:
            continue
        for i in range(0,n-1):
            a=temp[1:]+temp[0]
            if a==star:
                p+=i+1
                break
            temp=a
        else:
            print(-1)
            sys.exit()
    ans=min(ans,p)
print(ans)