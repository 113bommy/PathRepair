n,m,k=map(int,input().split())
ans="L"*(m-1)+"U"*(n-1)
for i in range(n):
    if i%2==0:
        ans+="R"*(m-1)+"D"
    else:
        ans+="L"*(m-1)+"D"
print(len(ans)-1)
print(ans[:len(ans)-1])