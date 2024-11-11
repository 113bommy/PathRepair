n, m = [int(num) for num in input().split()]
chips_per_round = (n * (n + 1)) // 2
remaining = m % chips_per_round
count = 1
while remaining:
    if remaining - count >= 0:
        remaining -= count
        count += 1
    else:
        break
print(remaining)
