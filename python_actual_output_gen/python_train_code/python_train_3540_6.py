N = int(input())
a = list(map(int, input().split()))

n = round(sum(a)//N)

ans = 0
for i in range(0,N):
    ans += (a[i] - n)**2

print(int(ans))