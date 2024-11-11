for _ in range(int(input())):
    n=int(input())
    L=[int(x) for x in input().split() ]
    L.reverse()
    print(*L)