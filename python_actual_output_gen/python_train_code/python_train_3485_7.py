t=int(input())
for i in range(t):
    n=int(input())
    counts=dict()
    for i in range(n):
        str=input()
        for i in str:
            counts[i]=counts.get(i,0)+1 
    for x in counts:
        if((counts[x]+n)%2!=0 ):
            print('NO')
            break
    else:
        print('YES')
    