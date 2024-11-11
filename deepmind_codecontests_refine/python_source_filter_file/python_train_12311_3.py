
t = int(input())

for _ in range(t):
    a, b, c = map(int, input().split())  # b >= 2
    if c < a:  # bulk price cheaper than single price
        a_better = -1
        b_better = 1
    elif c / b >= a:  # bulk unit price is same or more than single price
        a_better = 1
        b_better = -1
    else:  # bulk unit price is cheaper than single price
        a_better = 1
        b_better = b
    print(a_better, b_better)
