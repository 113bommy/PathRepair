k, d, t = [int(x) for x in input().split()]

n = 0
##while k > (n + 1) * d:
##    n += 1

n = int(k / d)

if n * d == k:
    n -= 1

cycle_len = (n + 1) * d

num_cycles = int(2 * t / ((n + 1) * d + k))

remaining_minutes = t - num_cycles * (k + ((n + 1) * d - k) / 2)

if remaining_minutes < k:
    print(num_cycles * cycle_len + remaining_minutes)
else:
    print(num_cycles * cycle_len + k + (remaining_minutes - k) * 2)
