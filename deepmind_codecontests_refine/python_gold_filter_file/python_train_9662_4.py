n = int(input())
H = list(map(int, input().split()))
cnt = H[0]
for i in range(1, n):
    cnt += max(H[i]-H[i-1], 0)
print(cnt)