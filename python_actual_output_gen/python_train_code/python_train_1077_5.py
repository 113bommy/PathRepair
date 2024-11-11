n=int(input())
w = [int(_) for _ in input().split()]
l=[999]*n
for i in range(1,n-1):
    l[i] = abs(sum(w[:i]) - sum(w[i:]))
print(min(l))
