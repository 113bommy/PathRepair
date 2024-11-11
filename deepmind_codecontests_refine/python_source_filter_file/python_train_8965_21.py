
t = int(input())

for i in range(t):

    l1, r1, l2, r2 = [int(i) for i in input().split()]

    if l1 == r1:
        print(l2, r1)
    else:
        print(l1, r1)