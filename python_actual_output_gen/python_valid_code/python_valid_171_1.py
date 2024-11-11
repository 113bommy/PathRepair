for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    odd = 0
    even = 0
    for i in range(n):
        if a[i]%2 == 0:
            even+=1
        else:
            odd+=1
    if odd == even:
        print('YES')
    else:
        print('NO')