n,m,k=map(int,input().split())
s,f=[],[]
ans=""

ans+="L"*m
ans+="U"*n
for i in range(1,n+1):
    if i%2!=0:
        ans+="R"*(m-1)
        ans+="D"
    else:
        ans+="L"*(m-1)
        ans+="D"
print(len(ans)-1)
print(ans[:len(ans)-1])