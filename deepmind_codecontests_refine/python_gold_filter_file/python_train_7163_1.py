n,a,b = map(int, input().split())


q=min(a, b)
w=max(0,a+b-n)

print(q,w)
