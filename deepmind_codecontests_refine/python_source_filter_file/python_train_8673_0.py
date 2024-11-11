for _ in range(int(input())):
        x=int(input())
        l=list(map(int,input().split()))
        l.sort()
        if(l[0]<0):
                print("NO")
        else:
                print("YES")
                print(101)
                a=[i for i in range(102)]
                print(*a)
        