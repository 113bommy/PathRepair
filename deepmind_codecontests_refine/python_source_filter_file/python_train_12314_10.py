for _ in range(int(input())):
    n = int(input())
    li = list(map(int, input().split()))
    s = list(set(li))
    if li == s:
        print("NO")
    else:
        print("YES")