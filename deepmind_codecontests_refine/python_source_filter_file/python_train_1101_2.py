from sys import stdin

B1, Q, L, M = map(int, stdin.readline().split())
bad = set(map(int, stdin.readline().split()))

if B1 == 0:
    if 0 in bad:
        print(0)
    else:
        print("inf")
elif B1 <= L and abs(Q) <= 1:
    # inf or 0
    if Q == 0: # B1, 0, 0, ...
        if B1 in bad and 0 in bad:
            print(0)
        elif B1 in bad:
            print("inf")
        elif 0 in bad:
            print(1)
        else:
            print("inf")
    elif Q == 1: # B1, B1, B1, ...
        if B1 in bad:
            print(0)
        else:
            print("inf")
    else: # B1, -B1, B1, ...
        if B1 in bad and -B1 in bad:
            print(0)
        else:
            print("inf")
else:
    # finite
    count = 0
    b = B1
    while abs(b) <= L:
        if b not in bad:
            count += 1

        b *= Q

    print(count)
