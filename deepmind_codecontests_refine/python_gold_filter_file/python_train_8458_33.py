for i in range(int(input())):
    n = int(input())
    print(*list(dict.fromkeys(map(int,input().split()))))
