k=int(input())

for y in range(1,2000):
    x=y-(k%y)
    if (k+x)//y+x<=1000000:
        print(y+1)
        arr=[0]*(y+1)
        arr[y-x:-1]=[-1]*x
        arr[-1]=(k+x)//y+x
        print(*arr)
        exit()
print(-1)