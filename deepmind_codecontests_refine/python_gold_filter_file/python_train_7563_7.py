# cook your dish here
n=int(input())
t=n+1

if n==0:
    ans=0
elif t%2==0:
    ans=t//2
else:
    ans=t
print(ans)