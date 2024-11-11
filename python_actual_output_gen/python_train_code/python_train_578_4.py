


n = int(input())


t= list(map(int,input().split()))


if t.count(0)==n:
    print('NO')
else:
    if sum(t)!=0:
        print('YES')
        print(1)
        print(*t)
    else:

        f=[]

        u=0
        for j in range(n):
            u+=t[j]
            if u!=0:
                print('YES')
                print(2)
                print(1,j+1)
                print(j+2,n)
                break
        
                
