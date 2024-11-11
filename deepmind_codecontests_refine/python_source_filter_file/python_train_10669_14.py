n=int(input())
a=list(map(int,input().split(' ')))
a=[int(i) for i in a]
ans=''
for i in range(n):
    s=1
    for j in range(1,n):
        if(a[j]>a[i]):  s+=1
    ans+=str(s)+' '
print(ans)