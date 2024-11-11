def f(n):
    ans=1
    for i in range(n):
        ans*=i+1
    return ans

n=int(input())
ans=2*f(n)/(n**2)
print(ans)



