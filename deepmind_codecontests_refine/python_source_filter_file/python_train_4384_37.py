H=list(map(int,input().split()))
w=H[0]
h=H[1]
k=H[2]
ans=0
while k !=0:
    k-=1
    ans+=2*w+2*h-4
    w-=2
    h-=2
print(ans)