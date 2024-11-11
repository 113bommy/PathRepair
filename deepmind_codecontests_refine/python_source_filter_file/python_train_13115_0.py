while 1:
    s=input()
    if '#' in s:break
    p=0
    e=[[]*2 for _ in range(10)]
    for x in s:
        if x=='b':e[p]+=['b']
        elif x=='/':p+=1
        else:e[p]+='.'*int(x)
    ans=''
    a,b,c,d=map(int,input().split())
    e[a-1][b-1],e[c-1][d-1]=e[c-1][d-1],e[a-1][b-1]
    for i in range(2):
        if i:ans+='/'
        a=0
        for j in e[i]:
            if j=='b':
                if a:ans+=str(a)
                ans+='b'
                a=0
            else:a+=1
        if a:ans+=str(a)
    print(ans)