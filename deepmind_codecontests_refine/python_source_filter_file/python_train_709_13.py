n=int(input())
l=list(map(int,input().split()))
n4=sum([i%4==0 for i in l])
n2=sum([i%2==0 for i in l])-n4
if n4>=max(n//2,1):
    print("Yes")
else:
    if (n//2)*2-n4*2<=n2:
        print("Yes"):
    else:print("No")