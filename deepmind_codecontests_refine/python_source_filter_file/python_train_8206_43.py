N = int(input())
A = list(map(int,input().split()))
sum_A = sum(A)
ans = 10**20
X = 0
for a in A:
    X += a
    ans = min(ans,abs(sum_A-2*X))
print(ans)