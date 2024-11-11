n,k,s=map(int, input().split())
l1 = [s]*k
l2 = [(s+1 if s == 10**9 else s-1)]*(n-k)
print(' '.join(map(str, (l1+l2))))