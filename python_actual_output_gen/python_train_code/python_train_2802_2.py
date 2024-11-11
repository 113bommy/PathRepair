n,k = list(map(int,input().split()))
for i in range(n):
    for j in range(n):
        if j == 0:
            print(k,end=' ')
        else:
            print(0,end=' ')
    print()