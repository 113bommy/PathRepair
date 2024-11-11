
t=int(input())

for _ in range(t):
    n=int(input())

    if n==1:
        print(1)
        continue
    if n%2==0:
        for i in range(n//2):
            print(i*2+2,2*i+1,sep=" ",end=" ")
        print()
    else:
        print(3,1,2,end=" ")
        for i in range(2,n//2):
            print(i*2+1,i*2,sep=" ",end=" ")
        print()