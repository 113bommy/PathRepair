n,m=map(int, input().split())
a=min(n,m)

p=a
n-=a
m-=a
c=0

leftover=max(n,m)

if leftover >= p:
    print(p)
    exit()
else:
    c=leftover
    p-=leftover
    c+=2*(p//3)
    if p%3==2:
        c+=1
    print(c)