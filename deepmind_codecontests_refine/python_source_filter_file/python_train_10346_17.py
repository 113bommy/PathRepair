n,k = map(int,input().split())
j = -2**10
for _ in range(n):
    f,t = map(int,input().split())
    j = max(j, f - max(t-k,0))
print (j)