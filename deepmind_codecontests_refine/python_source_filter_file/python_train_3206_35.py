a,b,k = map(int, input().split())
aa = max(0, a-k)
b = b + min(0, a-k)
print(aa,b)