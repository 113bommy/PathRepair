for _ in range(int(input())):
    n=int(input())
    s=input()
    f=0
    for i in range(n):
        d={'a':0,'b':0}
        for j in range(i,n):
            d[s[j]]+=1
            if d['a']==d['b']:
                f=1
                print(i,j)
                break
        if f==1:
            break
    if f==0:
        print(-1,-1)
