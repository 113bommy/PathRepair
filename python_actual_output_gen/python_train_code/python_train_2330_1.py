A = int(input())
B = int(input())
if B > A or (A + B) % 2 != 0:
    print(-1)
else:
    C = A - B
    C //= 2
    if (A & C) == 0:
        print(C, A - C)
    else:
        print(-1)