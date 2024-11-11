t=int(input())
while(t):
    n=int(input())
    N=input()
    l=list(N)
    l1,l2=[],[]
    for i in range(n):
        if(int(l[i])%2==0):
            l1.append(l[i])
        else:
            l2.append(l[i])
    if(len(l2)==0):
        print(-1)
    else:
        s=''
        for i in range(len(l2)):
            s+=str(l2[i])
        print(s)
    t=t-1