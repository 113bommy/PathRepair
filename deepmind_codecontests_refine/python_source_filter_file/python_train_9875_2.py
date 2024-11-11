N = int(input())
a = list(map(int, input().split()))
b = []
for i in range(N):
    b.append([a[i], i+1])
b.sort(reverse = True)
ans = [0]*(N+1)
mini = N+1

for i in range(N-1):
    mini = min(mini, b[i][1])
    if b[i+1][0] - b[i][0] < 0:
        ans[mini] += (b[i][0] - b[i+1][0])*(i+1)

ans[1] += N*min(b)
for i in range(N):
    print(ans[i+1])
