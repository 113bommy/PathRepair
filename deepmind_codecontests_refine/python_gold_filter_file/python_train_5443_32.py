for t in range(int(input())):
    l, r = list(map(int, input().split()))
    if r>=2*l:
        print("NO")
    else:
        print("YES")