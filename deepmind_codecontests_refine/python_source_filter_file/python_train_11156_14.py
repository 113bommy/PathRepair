def Input():
    tem = input().split()
    ans = []
    for it in tem:
        ans.append(int(it))
    return ans

n = Input()[0]
vis = [0 for i in range(100100)]
biao = []
for i in range(2,100100):
    if vis[i]==0:
        biao.append(i)
        cnt = i
        while cnt<100100:
            vis[cnt]=1
            cnt+=i
m = len(biao)
if n<3:
    print(-1)
else:
    edge = n*2
    l, r = 0, m-1
    while l<r:
        mid = (l+r)//2
        if biao[mid]<edge:
            l = mid+1
        elif biao[mid]>edge:
            r = mid
        else:
            l = mid
            break
    target = biao[l]
    print(target)
    for i in range(n):
        print(i+1,(i+1)%n+1)
    i, j = 0, 2
    while edge<target:
        print((i+1)%n+1, (j+1)%n+1)
        edge+=1
        i = (i-1+n)%n
        j = (j+1)%n