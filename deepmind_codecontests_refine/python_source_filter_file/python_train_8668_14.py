from sys import stdin,stdout
for _ in range(int(stdin.readline())):
    # n=int(stdin.readline())
    x,y,k=list(map(int,stdin.readline().split()))
    turns=(k*y+k-1)//(x-1)
    if (1+turns*(k-1))<(k*y+x):
        turns+=1
    print(turns+k)
