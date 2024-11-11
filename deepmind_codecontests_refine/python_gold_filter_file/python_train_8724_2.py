n,m=map(int,input().split())
c=set(range(m+1))
for i in range(n):
    a,*b=map(int,input().split())
    c&=set(b)
print(len(c))
