n = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(n):
    if A[A[i]-1] == i+1:
        ans += 1
print(ans//2)
