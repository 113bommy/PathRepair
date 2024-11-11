N,K=map(int,input().split())
V=[int(a) for a in input().split()]
able=min(N,K)
ans=0
 
for a in range(able+1):
    for b in range(able+1-a):
        if b==0:
            have=V[:a]
        else:
            have=V[:a]+V[-b:]
        have.sort()

        for i in range(min(a+b,able-a-b)+1):
            val=sum(have[i:])
            if ans<val:
                ans=val
 
print(ans)
