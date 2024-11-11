n,k=map(int,input().split())
ki=[0]*11
su=0
for x in input().split():
    t=int(x)
    ki[10-t%10]+=1
    su+=t//10
for i in range(1,10):
    t=min(k//i,ki[i])
    su+=t
    k-=t*i
t=k//10
su+=max(t,n*10-su)
print(su)