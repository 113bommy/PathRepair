n, m = [int(i) for i in input().split()]
sc = [list(map(int, input().split())) for _ in range(m)]


ans = -1
for i in range(10**(n-1) if n > 1 else 0, 10**n):
    for s, c in sc:
        if str(i)[s-1] != str(c):
            break
    else:
        ans = i
        break
print(ans)
