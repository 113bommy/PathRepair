import math
for i in range(int(input())):
    n=int(input())
    s=input()
    q=n 
    p=n 
    for i in range(n):
        if s[i]=='1':
            q=i 
            break
    for i in range(n-1,-1,-1):
        if s[i]=='1':
            p=i 
            break
    if q==n and p==n:
        print(n)
    elif q>p:
        print(2*(p+1))
    else:
        print(2*(n-q))