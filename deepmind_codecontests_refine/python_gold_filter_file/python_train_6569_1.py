n,h = map(int,input().split())

lis = []
for i in range(n):
    x,y = map(int,input().split())
    lis.append((x,y))

ans = lis[0][1] - lis[0][0]
end = 1
have = h
tot = lis[0][1] - lis[0][0]


for x in range(len(lis)):
    if end >= n:
        break
    if x:
        have += lis[x][0] - lis[x-1][1]
        have = min(have,h)
        tot -=  lis[x-1][1] - lis[x-1][0]
        tot = max(tot,lis[x][1] - lis[x][0])
        end = min(n-1,max(end,x+1))

    while have:
        need = lis[end][0] - lis[end-1][1]
        if have > need:
            have -= need
            tot += lis[end][1] - lis[end][0]
        else:
            break

        end += 1
        if end == n:
           break

    ans = max(ans,tot)


print(ans + h)










