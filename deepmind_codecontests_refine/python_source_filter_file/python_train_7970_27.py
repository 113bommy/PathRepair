n, k = [int(i) for i in input().split()]
t, i = 240, 0
while n >= k and i <= n:
    i += 1
    t -= 5 * i
print(i - 1)
