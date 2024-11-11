(n, k) = (int(i) for i in input().split())
print(int((n-k)>0), min(k*2, n-k))