t=int(input())
while(t!=0):
    f1=int(0)
    a= input()
    c=0
    ans=0
    for s in range(len(a)):
        if a[s]=='1' and f1==0:
            c=0
            f1=1
        elif a[s]=='1' and f1==1:
            ans+=c
            f1=0
        else:
            c+=1
    t-=1
    print(ans)


