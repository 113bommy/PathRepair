N,P=map(int,input().split())
S=str(input())
ans=0

if 10%P==0:
    for i in range(N):
        if int(S[i])%P==0:
            ans+=i+1
else:
    rem = [0]*P
    mod = 0
    ten = 1
    rem[mod]=1
    for i in range(N):
        mod=(mod+int(S[N-i-1])*ten)%P
        ten=ten*10%P
        rem[mod]+=1
    for j in rem:
        ans+=(j*(j-1))//2
print(ans)
