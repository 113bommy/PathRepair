t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(c) for c in input().split()]
    s1 = 0
    s2 = 0
    for i in range(n):
        if a[i]%2==0:
            s1+=1
        else:
            s2+=1
    if s1==s2:
        print('YES')
    else:
        print('NO')