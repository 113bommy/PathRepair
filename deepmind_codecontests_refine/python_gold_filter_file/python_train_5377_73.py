n=int(input())
ans=0
m=0
k=1
for i in range(100000):
        if (n-k) % k==0:
            m=n-k
            if m%k==0:
                ans+=1
                k+=1
        else:
            k+=1
print(ans-1)