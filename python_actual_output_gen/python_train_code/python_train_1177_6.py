X, Y, A, B, C = map(int, input().split())
p = sorted(list(map(int, input().split())), reverse=True)[:A]
q = sorted(list(map(int, input().split())), reverse=True)[:B]
r = list(map(int, input().split()))
ans = sum(sorted(p + q + r, reverse=True)[:X + Y])
print(ans)