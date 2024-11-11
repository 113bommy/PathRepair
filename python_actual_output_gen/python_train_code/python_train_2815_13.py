N=int(input())
ans=0
i=1
while i*(i+1)<=N:
    if N%i==0:
        ans+=(N-i)//i
    i+=1
print(ans)