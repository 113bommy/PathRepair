import random
n=int(input())
for i in range(n):
    a,b,c,d=list(map(int , input().split()))
    x=random.randint(a,b)
    y=random.randint(c,d)
    if x==y:
        x=random.randint(a,b)
        y=random.randint(c,d)
    else:
        print(f"{x} {y}")