n,a,b=map(int,input().split())
w=input()
now,ans=0,0
for c in w:
    if c=='*':
        now=0
        continue
    if a==b==0:
        break
    if now==0:
        if a>b:
            now=2
            a-=1
        else:
            now=1
            b-=1
        ans+=1
    else:
        if now==1:
            if a==0:
                now=0
                continue
            else:
                a-=1
                now=2
                ans+=1
        else:
            if b==0:
                now=0
                continue
            else:
                a-=1
                now=1
                ans+=1
print(ans)
        
