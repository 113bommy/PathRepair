t=int(input())
for i in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    pos=neg=0
    positive=[]
    negative=[]
    for i in range(n):
        if l[i]<0:
            neg+=l[i]
            negative.append(l[i])
        else:
            pos+=l[i]
            positive.append(l[i])
    if pos==-1*neg:
        print('NO')
    elif -1*neg>pos:
        print('YES')
        print(*negative,end=' ')
        print(*positive)
    else:
        print('YES')
        positive.sort(reverse=True)
        print(*positive,end=' ')
        print(*negative)
