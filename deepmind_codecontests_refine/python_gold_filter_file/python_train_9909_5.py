n=int(input())
a=int(input())
b=int(input())
ans = n
b*=5
for i in range(n//a+1):
    t=n-i*a
    z=t-(t//b)*b
    ans = min(ans,z)
print(ans)