n=int(input())
i,ans=1,0
while i*i+i<n:
    if (n-i)%i==0: ans+=(n-i)//i
    i+=1
print(ans)