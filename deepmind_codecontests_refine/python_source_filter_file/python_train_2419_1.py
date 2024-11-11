t=int(input())
for i in range(0,t):
    s=input().split(" ")
    k=list(map(int,s))
    if(k[0]%k[1]==0):
        print("0")
    else:
        l=(k[0]%k[1])
        print(l)
        