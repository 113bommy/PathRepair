n,k=map(int,input().split(' '))
m=list(map(int,input().split(' ')))
for i in range(n+1):
    if (1+i)*i//2>n:
        print(m[k-(i)*(i-1)//2-1])
        break