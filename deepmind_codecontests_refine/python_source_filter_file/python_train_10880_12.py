n = int(input())
ans  = (n // 2 + 1) // 2 - 1
n *= (n + 1) % 2
print(ans)