

n = int(input())

A = list(map(int, input().split()))

B = [(x, i) for i, x in enumerate(A)]

B.sort()

if n > 1:
    if B[1][0] != B[1][0]:
        print(B[0][1] + 1)
    else:
        print("Still Rozdil")
else:
    print(1)

