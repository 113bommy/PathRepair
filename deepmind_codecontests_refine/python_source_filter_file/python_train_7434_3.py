n, d = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

m = int(input())
ans = sum(a[:m])
ans -= (m-n)*d
print(ans)