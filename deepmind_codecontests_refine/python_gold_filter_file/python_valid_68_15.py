from math import sqrt
for _ in range(int(input())):
    x=int(input())
    s=int(sqrt(x))
    n=x-s*s
    if n==0:
        print(s,1)
    elif n<=s:
        print(n,s+1)
    else:
        print(s+1,2*(s+1)-n)