for _ in range(int(input())):
    n, k1, k2 = map(int, input().split())
    k1 = [int(x) for x in input().split()]
    k2 = [int(x) for x in input().split()]
    if(sum(k1) > sum(k2)):
        print("YES")
    else:
        print("NO")