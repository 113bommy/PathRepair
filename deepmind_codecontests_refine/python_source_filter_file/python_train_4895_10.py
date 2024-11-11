n=int(input())
maxn=-1
minn=int(input())

for j in range(1, n):
    r = int(input())
    maxn = max(maxn, r - minn)
    minn = min(minn, r)
    
print(maxn)
