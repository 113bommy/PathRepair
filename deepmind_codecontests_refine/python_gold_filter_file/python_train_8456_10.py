t = int(input())

for _ in range(t):

    n = int(input())

    for k in range(2,30):
        if n%((2**k)-1) == 0:
            print(n//((2**k)-1))
            break
    