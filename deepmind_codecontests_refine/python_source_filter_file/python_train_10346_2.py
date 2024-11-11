n,k = map(int,input().split())
max=-1000000
for i in range(n):
    f,t = map(int,input().split())
    if t <= k:
        s = f
    else:
        s = f-(t-k)
    if s>max:
        max=s
print(max)