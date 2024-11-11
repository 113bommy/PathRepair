N = int(input())
A = []
for _ in range(N):
    x, l = map(int, input().split())
    A.append((x+l-1, x-l+1))
A.sort()
now = A[0][0]
ans = 1
for r, l in A:
    if now<l:
        ans+=1
        now = r
print(ans)
