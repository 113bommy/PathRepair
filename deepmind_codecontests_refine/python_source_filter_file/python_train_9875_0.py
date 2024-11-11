N = int(input())
A = [(a, i) for i, a in enumerate(map(int, input().split()))]
A.sort(reverse=True)
A.append((0, 0))

ans = [0] * N
now = float('inf')

for j, (a, i) in enumerate(A[:N], start=1):
    now = min(now, i)
    ans[now] += j * (now - A[j][0])

print(*ans, sep='\n')
