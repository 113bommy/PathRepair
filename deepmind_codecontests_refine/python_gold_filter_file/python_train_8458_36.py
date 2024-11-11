for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    x = set()
    ans = []
    for i in a:
        if i not in x:
            ans.append(i)
            x.add(i)
    print(*ans)