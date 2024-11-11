import math
def formula(n, a, b):
    if (a+b)%2==0:
        return ((a-1)*n+b+1)//2 
    else:
        return ((a-1)*n+b+1)//2 + math.ceil(n*n/2)
n, q = map(int, input().split())
ans = []
for i in range(q):
    x, y = map(int, input().split())
    ans.append(formula(n, x, y))
print(*ans)