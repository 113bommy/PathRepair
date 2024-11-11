t = int(input()) ##hello
while (t):
    x = input().split()
    n,x = int(x[0]), int(x[1])
    cnt = [0 for i in range(n+1)]
    for i in range(n-1):
        u = input().split()
        u,v = int(u[0]),int(u[1])
        cnt[u] += 1
        cnt[v] += 1
    if (cnt[x] == 1):
        print('Ayush')
    else:
        if (n % 2 == 0):
            print('Ayush')
        else:
            print('Ashish')
    t -= 1