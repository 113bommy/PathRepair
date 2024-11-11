n=int(input())

if n==0:
    print(0)
else:
    ans=""
    while n!=0:
        ans=str(n%2)+ans
        n=-1*(n//2)
ans=int(ans)
print(ans)