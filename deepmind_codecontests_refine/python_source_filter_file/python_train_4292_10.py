import math as m
t=int(input())

for i in range(t):
    n=int(input())
    a=0
    b=0
    c=0

    for j in range(2,int(m.sqrt(n))+1):
        if n%j==0:
            a=j
            n=n/j
            break
    for k in range(a+1,int(m.sqrt(n))+1):
        if n%k==0:
            b=k
            c=n/k
            break

    if a>1 and b>1 and c>1 and  ( a!=b or a!=c or b!=c) :
        print("YES")
        print(int(a),int(b),int(c))
    else:
        print("NO")