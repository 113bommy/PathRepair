def q(s,b):
    if not s or b<0:return 0
    n,f=[],[]
    for i in s:
        if i&(1<<b):n+=i,
        else:f+=i,
    if not n:return q(f,b-1)
    if not f:return q(n,-1)
    return min(q(n,b-1),q(f,b-1))+2**b
input()
print(q([*map(int,input().split())],32))