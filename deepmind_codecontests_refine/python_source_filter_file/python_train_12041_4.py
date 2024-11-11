n=int(input())
if(n<4):
    print(-1)
else:
    print(1,2)
    print(2,3)
    print(1,4)
    for i in range(4,n):
        print(1,i+1)

for i in range(n-1):
    print(1,i+1+1)