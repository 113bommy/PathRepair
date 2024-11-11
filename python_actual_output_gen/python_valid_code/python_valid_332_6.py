n, m = map(int, input().split())
if m-n>4:
    print("0")
else:
    if m==n:
        print("0")
    else:
        ans=1
        for i in range(n+1,m+1):
            ans*=i
        ans=str(ans)
        # print(ans)
        print(ans[len(ans)-1])