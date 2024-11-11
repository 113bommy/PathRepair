t = int(input())
while t:
    t-=1
    n = int(input())
    ls = list(map(int, input().split()))
    if ls[-1]==0:
        print(*list(range(1, n+2)))
    elif ls[0]==1:
        print(n+1, end=" ")
        print(*list(range(1, n+1)))
    else:
        for i in range(n):
            if ls[i]==0:
                print(i+1, end = ' ')
            else:
                print(n+1, end= ' ')
                print(*list(range(i+2, n+1)))
                break
    