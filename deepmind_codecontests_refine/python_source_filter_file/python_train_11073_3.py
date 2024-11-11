n=int(input())
if n == 1 or n == 2:
    print(-1)
else:
    print(n,end=" ")
    for i in range(1,n,+1):
        print(i,end=" ")