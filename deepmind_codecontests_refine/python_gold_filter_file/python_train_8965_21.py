
t = int(input())

for i in range(t):

    l1, r1, l2, r2 = [int(i) for i in input().split()]

    if l1 == l2:
        print(r1, l2)
    else:
        print(l1, l2)