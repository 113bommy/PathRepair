for i in range(int(input())):
    l = list(map(int, input().split()))
    if l[1] == 2 and l[0] == 2:
        print("YES")
    elif l[1] or l[0] == 1:
        print("YES")
    else:
        print("NO")