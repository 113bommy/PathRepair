n,k=[int(x) for x in input().split()]
a=[int(x) for x in input()]

ans=a[:k]
while len(ans)<n:
    ans.append(ans[len(ans)-k])

if ans<a:
    i=k-1
    while True:
        ans[i]+=1
        if ans[i]==10:
            ans[i]=0
            i-=1
        else:
            break
    for i in range(k,n):
        ans[i]=ans[i-k]
print(n)
print(''.join([str(x) for x in ans]))