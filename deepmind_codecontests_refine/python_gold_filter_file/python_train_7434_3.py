n, d = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

m = int(input())
ans = sum(a[:m])
ans -= (max(0,m-n))*d
print(ans)