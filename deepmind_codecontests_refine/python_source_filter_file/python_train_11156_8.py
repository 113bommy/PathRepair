from sys import stdout
pr=[0]*(10**6)
pr[0]=pr[1]=1
for i in range(2,10**6):
    if pr[i]==0:
        for j in range(2*i,10**6,i):
            pr[j]=1
n=int(input())
c=[2]*n
ans=[]
for i in range(1,n):
    ans.append([i-1,i])
ans.append([n-1,0])
dis=2
ed=n
fl=0
for i in range(n):
    if pr[ed]!=0:
        ans.append([i,(i+2)%n])
        ed+=1
    else:
        fl=1
        break
if fl==1:
    print(ed)
    for i in ans:
        stdout.write(str(i[0]+1)+' '+str(i[1]+1)+'\n')
else:
    print(-1)

            
            