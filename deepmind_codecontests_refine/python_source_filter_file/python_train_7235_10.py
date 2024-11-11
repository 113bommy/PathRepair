n = int (input())
L = list(map(int, input().split()))
ans = L[0]
for i in range (0, len(L) - 1) :
    ans += abs(L[i + 1] - L[i])
print(ans)