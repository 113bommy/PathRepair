n=int(input())
res=[[0,0,0]]*n
for i in range(n):
    a=int(input())
    b=a%10
    if b==0:
        c=a//5       
        res[i]=[0,c,0]
    elif b==1:
        a=a-3-3-5
        c=a//5
        if a<0:
            res[i]=(-1)
        else:
            res[i]=(2,c+1,0)
    elif b==1:
        a=a-3-3-5
        c=a//5
        if a<0:
            res[i]=(-1)
        else:
            res[i]=(2,c+1,0)
    elif b==2:
        a=a-(3*4)
        c=a//5
        if a<0:
            print(-1)
        else:
            res[i]=(4,c,0)
    elif b==3:
        a=a-3
        c=a//5
        if a<0:
            res[i]=(-1)
        else:
            res[i]=(1,c,0)
    elif b==4:
        a=a-7-7
        c=a//5
        if a<0:
            res[i]=(-1)
        else:
            res[i]=(0,c,2)
    elif b==5:
        c=a//5
        if a<0:
            res[i]=(-1)
        else:
            res[i]=(0,c,0)
    elif b==6:
        a=a-3-3
        c=a//5
        if a<0:
            res[i]=(-1)
        else:
            res[i]=(2,c,0)
    elif b==7:
        a=a-7
        c=a//5
        if a<0:
            res[i]=(-1)
        else:
            res[i]=(0,c,1)
    elif b==8:
        a=a-3-5
        c=a//5
        if a<0:
            res[i]=(-1)
        else:
            res[i]=(1,c+1,0)
    elif b==9:
        a=a-3-3-3
        c=a//5
        if a<0:
            res[i]=(-1)
        else:
            res[i]=(3,c,0)
for i in range(n):
    if(res[i]==-1):
        print(-1)
    else:
        print(res[i][0],res[i][1],res[i][2])
