n = int(input())
a = list(map(int, input().split()))
ans = 0
for q in range(n):
    if q % 2 == 0:
        ans += (q+1)//2
    else:
        ans += q//2
print(min(ans, sum(a)-ans))
