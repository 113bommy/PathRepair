n,k=map(int,input().split())
if(k>(n*(n-1))//2):
    print('no solution')
else:
    for i in range(n):
        print(i,n-i)
