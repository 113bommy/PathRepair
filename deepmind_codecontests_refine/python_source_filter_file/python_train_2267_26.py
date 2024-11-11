X,N = map(int,input().split())

P = set(map(int,input().split()))

_,res = min((abs(X-y),y) for y in range(-1,101) if y not in P)
print(res)