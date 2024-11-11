n=int(input())
c=input()
a=input()

an=[0 for i in range(n)]
for i in range(n):
    if c[i]=='1' and a[i]=='1':an[i]=3
    elif a[i]=='1':an[i]=1
    elif c[i]=='1':an[i]=2
a1=[]
a2=[]
a3=[]
a4=[]
for i in range(n):
    if an[i]==1:a1.append(i)
    elif an[i]==2:a2.append(i)
    elif an[i]==3:a3.append(i)
    else:a4.append(i)
#print(a1,a2,a3,a4)
l1,l2,l3,l4=len(a1),len(a2),len(a3),len(a4)

ans=[]
su=0
while (l2+l3)!=l1+su:
    #print((l2+l3),l1+su,ans)
    if l1>(l2+l3):
        if l1==0:print(-1);exit()
        ans.append(a1.pop())
        l1-=1
    else:
        if (l1+su+1)<(l2+l3-1):
            if l3==0:
                if l2!=0:
                    a2.pop()
                    l2-=1
                else:
                    print(-1);exit()
            else:
                a3.pop()
                l3-=1
                su+=1
        else:
            if l2!=0:
                a2.pop()
                l2-=1
            else:
                print(-1);exit()
#print(ans,a2,a3,a1)
ans.extend(a2)
ans.extend(a3)
l=len(ans)
if l>n//2:print(-1);exit()
for i in range(n//2-l):
    if a4:ans.append(a4.pop())
    else:print(-1);exit()
for i in range(n//2):
    ans[i]+=1
print(*ans)

        

