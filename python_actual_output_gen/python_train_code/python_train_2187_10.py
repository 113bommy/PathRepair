
n,k=map(int,input().split())

l=list(map(int,input().split()))
mod=10**9+7

ain=0
aout=0

for i in range(n):
    for j in range(n):
        if l[i]>l[j]:
            aout+=1
            if i>j:
                ain+=1
ain*=k
aout*=k*(k-1)//2
print((ain+aout)%mod)

