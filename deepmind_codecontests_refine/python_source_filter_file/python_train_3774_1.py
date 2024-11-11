for _ in range(int(input())):
    n,m=map(int,input().split())
    ls=[]
    for i in range(n):
        ls.append(list(input()))
    ans=-1
    for i in range(m):
        startchar='a'
        st=ls[0]
        for j in range(26):
            st[i]=chr(ord(startchar)+j)
            done=True
            for k in range(1,n):
                cnt=0
                f=0
                for p in range(m):
                    if(ls[k][p]!=st[p]):
                        cnt+=1
                    if(cnt==2):
                        f=1
                        break
                if(f==1):
                    done=False
                    break
            if(done):
                ans=st
                break
        if(ans!=-1):
            break
    if(ans==-1):
        print(ans)
    else:
        print(''.join(ans))