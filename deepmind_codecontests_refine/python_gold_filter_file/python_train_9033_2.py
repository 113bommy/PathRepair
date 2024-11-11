n,k=map(int,input().split())
s=list(map(int,input().split()))
s.sort(reverse=True)
del s[:k]
print(sum(s))