for _ in range(int(input())):
    arr = sorted([int(a) for a in input().split()], reverse=True)
    l1, l2, l3 = arr[0], arr[1], arr[2]
    
    if l1==l2 and l2==l3 and l1!=1: print("YES")
    elif l2==l3 and not l1%2: print("YES")
    elif l1==l2 and not l3%2: print("YES")
    elif l1== (l2+l3): print("YES")
    else: print("NO")