q=int(input())
for i in range(q):
    b,w=map(int,input().split())
    mn=min(b,w)
    mx=max(b,w)
    if(mx>3*mn+1):
        print('NO')
    else:
        if(b<=w):
            bk=[]
            wh=[]
            c=0
            for i in range(b):
                bk.append((3,3+c))
                c+=2
            c=0
            for i in range(b):
                wh.append((3,4+c))
                c+=2
                
            wh.append((3,2))
            for i in range(0,len(bk)):
                r=bk[i]
                wh.append((r[0]+1,r[1]))
                wh.append((r[0]-1,r[1]))

            wh=wh[:w]

            ans=bk+wh
            print('YES')
            for i in ans:
                print(*i)
        else:
            bk=[]
            wh=[]
            c=0
            for i in range(w):
                wh.append((3,2+c))
                c+=2
            c=0
            for i in range(w):
                bk.append((3,3+c))
                c+=2
                
            bk.append((3,1))
            for i in range(0,len(wh)):
                r=wh[i]
                bk.append((r[0]+1,r[1]))
                bk.append((r[0]-1,r[1]))

            bk=bk[:b]

            ans=bk+wh
            print('YES')
            for i in ans:
                print(*i)
                

