for t in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    l = l[::-1]
    p = []
    for i in range(n):
        if i<=(n//2):
            p.append(-1*i)
        else:
            p.append(i)
    
    print(*p)
    