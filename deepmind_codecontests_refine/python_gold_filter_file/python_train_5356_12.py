p,n=map(int,input().split())
l=list(range(p))
c=-1
for i in range(n):
    a=int(input())
    if c==-1:
        a=a%p
        if a not in l:
            c=i+1
        else:
            l.remove(a)
if c==-1:
    print("-1")
else:
    print(c)
