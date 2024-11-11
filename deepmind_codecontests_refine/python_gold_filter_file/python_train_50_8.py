n,m=map(int, input().split())
a=set()
for i in range(n):
    b=list(map(int,input().split()))
    a.update(b[1:])
print(['NO','YES'][len(a)==m])

