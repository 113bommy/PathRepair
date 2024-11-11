n = int(input())
l = sorted(list(map(int, input().split())))
if n != 1:
    l1 = []
    l2 = []
    ok = True
    l1.append(l[0])
    
    for i in range(1, n):
        if l[i - 1] != l[i]:
            l1.append(l[i])
        else:
            l2.append(l[i])
            
    for i in range(1, len(l2)):
        if l[i - 1] == l[i]:
            ok = False;
            break;
    
    if not ok:
        print("NO")
    else:
        print("YES")
        print(len(l1))
        print(*l1)
        print(len(l2))
        print(*l2[::-1])
else:
    print("YES")
    print(1)
    print(*l)
    print(0)
    print()