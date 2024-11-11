import math

t = int(input())
for _ in range(t):
    n, k = map(int, input().split(" "))
    a = list(map(int, input().split(" ")))
    diff = len(set(a))
    if k == 1:
        print(1 if diff == 1 else -1)
    elif k==diff:
        print(1)
    else:
        print(math.ceil((diff+1)/k))
