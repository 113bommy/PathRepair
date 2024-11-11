import math
n=int(input())
lst = list(map(int, input().strip().split(' ')))
lst.sort(reverse=True)
if n==1:
    print(lst[0])
elif n==2:
    print(sum(lst)*3)
else:
    c=n-1
    s=0
    for i in range(n):
        if i==0 or i==1:
            s+=n*lst[i]
        else:
            s+=lst[i]*c
            c-=1
    print(s)
    