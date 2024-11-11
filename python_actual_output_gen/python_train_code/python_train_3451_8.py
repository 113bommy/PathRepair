t = int(input())
for i in range(t):
    n, x = map(int,input().split())
    cnt = 0
    for j in range(n-1):
        a,b = map(int,input().split())
        if a == x:
            cnt += 1
        if b == x:
            cnt += 1
    if cnt == 1 or n%2 == 0:
        print('Ayush')
    else:
        print('Ashish')