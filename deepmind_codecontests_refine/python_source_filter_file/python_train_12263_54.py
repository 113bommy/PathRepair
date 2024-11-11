N = int(input())
ans = ":("
for i in range(N):
    if int(i*1.08) == N:
        ans = i
print(ans)