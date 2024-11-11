from math import ceil

hh, mm = map(int, input().split())

H, D, C, N = map(float, input().split())

if hh >= 20:
    num = ceil(H / N)
    print(0.8 * num * C)
else:
    num = ceil(H / N)
    num_wait = ceil((H + (20 * 60 - hh * 60 + mm) * D) / N)
    
    cost = num * C
    cost_wait = 0.8 * num_wait * C
    
    print(min(cost, cost_wait))