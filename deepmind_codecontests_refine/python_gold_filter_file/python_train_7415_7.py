n, k = [int(x) for x in input().split()]

max_val = 0
num_ways_nobar = 0
num_ways_bar = 1

pr = 998244353

ps = [int(x) for x in input().split()]

for i, p in enumerate(ps):
    if p + k > n:
        max_val += p
        num_ways_nobar = num_ways_bar
    else:
        num_ways_bar = (num_ways_bar + num_ways_nobar) % pr

print(max_val, num_ways_nobar)
