n = int(input())
s = [int(input()) for _ in range(n)]
j = sorted(s)
ans = len(set(s[::2]) ^ set(j[::2]))
print(ans)