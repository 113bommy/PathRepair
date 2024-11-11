n, m, k=map(int,input().split())
sp = sorted(map(int,input().split()))
socket_count = 0
sp_count = 0
sc = 0
if k>=m:
    print(0)
    exit()
for i in range(n):
    if k > 0:
        n -= 1
        k -= 1
        sp_count += 1
        sc = sc + sp.pop()
        socket_count = sc + k
        if socket_count >= m:
            print (sp_count)
            exit()
    else:
        n -= 1
        sp_count += 1
        socket_count -= 1
        socket_count = socket_count + sp.pop()
        if socket_count>= m:
            print (sp_count)
            exit()


print(-1)



