import math
def query(n, a, b):
    if (a+b)%2 == 0:
        temp = ((a-1)*n + b+1)//2
    else:
        temp = (n**2 + n*(a-1) + b+1)//2
    return temp
n, q = map(int, input().split())
ans = []
for i in range(q):
    a, b = map(int, input().split())
    ans.append(query(n, a, b))
for a in ans:
    print(a)