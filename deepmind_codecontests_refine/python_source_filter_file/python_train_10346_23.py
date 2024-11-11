#276A
n,k=map(int,input().split())
s = -1000000
for _ in range(n):
    f,t = map(int,input().split())
    if t-k>0:
        f = f-(t-k)
        s = max(f,s)
    else:
        s = max(f,s)
print(s)        