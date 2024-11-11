n,m,k=map(int,input().split())
a=[['' for x in range(m)] for x in range(n)]
dopi=0
for i in range(n):
    a[i]=list(input())
    dopi+=a[i].count('.')
b=a.copy()
if k!=0:
    pos=[-1,-1]
    for lin in range(n):
        if pos!=[-1,-1]:
            break
        for i in range(m):
            if a[lin][i]=='.':
                pos=[i,lin]
                break
    import collections


    k=dopi-k
    #print (k)
    if (pos!=[-1,-1]):
        b[pos[1]][pos[0]]='1'
        k-=1
        q=collections.deque([pos])
        #print('b',b)
    #print (pos)
    while (len(q)!=0)and(k>0):
        
        now=q.popleft()
        if (now[1]-1>=0)and(b[now[1]-1] [now[0]]=='.'):
            k-=1
            b[now[1]-1] [now[0]]='1'
            q.append([now[0],now[1]-1])
            if k==0:
                break
        if (now[1]+1<n)and(b[now[1]+1] [now[0]]=='.'):
            k-=1
            b[now[1]+1] [now[0]]='1'
            q.append([now[0],now[1]+1])
            if k==0:
                break
        if (now[0]-1>=0)and(b[now[1]] [now[0]-1]=='.'):
            k-=1
            b[now[1]] [now[0]-1]='1'
            q.append([now[0]-1,now[1]])
            if k==0:
                break
        if (now[0]+1<m)and(b[now[1]] [now[0]+1]=='.'):
            k-=1
            b[now[1]] [now[0]+1]='1'
            q.append([now[0]+1,now[1]])
            if k==0:
                break
        #print(k)
        #for i in b:
        #    print (i)
        #print('-'*9)


    for i in range(n):
        for j in range(m):
            if b[i][j]=='1':
                b[i][j]='.'
            elif b[i][j]=='.':
                b[i][j]='X'
        s=''
        for j in b[i]:
            s+=str(j)
        print(s)
else:
    for i in range(n):
        s=''
        for j in b[i]:
            s+=str(j)
        print(s)

