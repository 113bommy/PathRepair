n = int(input())
a = [int(input()) for _ in range(n)]
ans = 'second' if any(a[i] % 2 == 0 for i in range(n)) else 'first'
print(ans)
