from sys import stdin
input=stdin.readline

for i in range(int(input())):
    n,m,k=map(int,input().split())
    h=list(map(int,input().split()))
    bag=m
    for i in range(n-1):
        bag+=h[i]
        h[i]=0
        
        dif=h[i+1]-h[i]
        if dif<k:
            continue
        elif dif>k and dif-k<=bag:
            bag-=dif-k

        else:
            print('NO')
            break
    else:
        print('YES')