import math 
n=int(input())
res=[chr(x) for x in range(ord('a'), ord('z') + 1)] 
res1=[chr(x) for x in range(ord('A'), ord('Z') + 1)] 
res+=res1
res2=[0,1,2,3,4,5,6,7,8,9,]  
res+=res2 
for i in range(n):
    r,c,f=map(int,input().split())
    s=[]
    e=0
    for j in range(r):
        k=input()
        e+=k.count('R')
        s.append(k)
    w=e%f 
    e=math.ceil(e/f)
    e=int(e)
    cou=f
    cou1=1
    ans=[[0 for i in range(c)]for j in range(r)]
    rw=0
    co=0
    inc=1
    while(cou>1):
        #print(cou)
        if w!=0 and cou1==w+1:
            e-=1 
        cur=0
        while(cur<e):
            ans[rw][co]=res[cou1-1] 
            #print(rw,co)
            if s[rw][co]=='R':
                cur+=1
            co+=inc
            if inc==1 and co==c:
                rw+=1 
                co=c-1
                inc=-1
            elif inc==-1 and co==-1:
                rw+=1 
                co=0
                inc=1 
        cou-=1
        cou1+=1 
        #print(ans)
    for jk in range(r):
        for ik in range(c):
            if ans[jk][ik]==0:
                ans[jk][ik]=res[f-1] 
    for jk in range(r):
        print(*ans[jk],sep="")
            
    