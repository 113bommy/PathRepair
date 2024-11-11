n, m = map(int, input().split())
ans = m//n

while ans > 0:
    if m%ans == 0:
        if m//ans >= n:
            break
    else:
        ans -= 1

print(ans)