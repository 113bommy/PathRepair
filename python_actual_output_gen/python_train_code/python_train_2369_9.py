n=int(input())
if(n//2>18):
    print(-1)
    exit()
if(n%2==0):
    for i in range(n//2):
        print(8,end="")
else:
    for i in range(n//2):
        print(8,end="")
    print(4,end="")