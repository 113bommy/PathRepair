N = int(input())
*A, = map(int,input().split())

A.sort()

for i,a in enumerate(A):
    if a>=0:break
B = A[:i]
C = A[i:]

ans = []
if not B:
    x = C[0]
    for a in C[1:-1]:
        ans.append((x,a))
        x -= a
    ans.append((C[-1],x))
    x = C[-1] - x
elif not C:
    x = B[-1]
    for a in B[:-1]:
        ans.append((x,a))
        x -= a
else:
    x = B[0]
    for a in C[1:]:
        ans.append((x,a))
        x -= a
    ans.append((C[0],x))
    x = C[0]-x
    for a in B[1:]:
        ans.append((x,a))
        x -= a

print(x)
for out in ans:
    print(*out)