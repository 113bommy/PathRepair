n,k=map(int,input().split())
m = list(map(int,input().split()))
m.sort(reverse=True)
print(k+sum(m[k:]))
