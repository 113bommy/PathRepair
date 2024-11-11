l1 = [int(x)%2 for x in input().split()]
l2 = [int(x)%2 for x in input().split()]
if not l1[0]:
    if not l1[-1]:
        print("even")
    else:
        print("odd")
else:
    if sum(l2)%2:
        print("odd")
    else:
        print("even")