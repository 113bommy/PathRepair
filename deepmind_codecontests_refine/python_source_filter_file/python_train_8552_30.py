n = int(input())
l = list(map(int,input().split()))
flag = False
if sum(l[:n]) == sum(l[n:]):
    for i in range(n):
        for j in range(n):
            if l[i] != l[n+j]:
                l[i],l[n+j] = l[n+j], l[j]
                flag = True
                print(*l)
                break
        if flag:
            break
    else:
        print(-1)
else:
    print(*l)