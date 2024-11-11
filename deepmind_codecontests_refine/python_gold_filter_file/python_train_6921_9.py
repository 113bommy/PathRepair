


n=int(input())


t = list(map(int,input().split()))
t.sort()


pre=[t[0]]
ans=1

for i in range(1,n):

    if pre[-1]<=t[i]:
        ans+=1
        pre.append(pre[-1]+t[i])


print(ans)

