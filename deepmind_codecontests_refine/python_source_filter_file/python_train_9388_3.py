T = int(input())
for i in range(0, T):
    k, x = (int(i) for i in input().split())
    best_diff = None
    max_strike = None
    for j in range(k):
        strike, heads = (int(i) for i in input().split())
        if max_strike is None or strike > max_strike:
            max_strike = strike
        if strike > heads and (best_diff is None or best_diff < strike - heads):
            best_diff = strike - heads
    x -= max_strike
    if x <= 0:
        print(1)
    if best_diff is None:
        print(-1)
    else:
        print(1 + x // best_diff + int((x % best_diff) > 0))