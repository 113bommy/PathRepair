from bisect import bisect_right as br
maxx=[]
minn=[]
c=0
n=int(input())
for _ in range(n):
    t=list(map(int,input().split()))
    t=t[1:]
    flag=False
    for k in range(len(t)-1):
        if(t[k]<t[k+1]):
            flag=True
            break
    if(not flag):
        maxx.append(max(t))
        minn.append(min(t))
    else:
        c+=1
ans=0
maxx.sort()
minn.sort()


for k in minn:
    ans+=len(maxx)-br(maxx,k)

print(pow(n,2)-pow((n-c),2)+ans)



'''
#code forces hello 2020 problem A
m,n=map(int,input().split())
mm=list(input().split(' '))
nn=list(input().split(' '))
for _ in range(int(input())):
    k=int(input())
    mmm=k%m
    nnn=k%n
    mmm= (mmm+m-1)%m
    nnn=(nnn+n-1)%n
    ans=mm[mmm]+nn[nnn]
    print(ans)


'''