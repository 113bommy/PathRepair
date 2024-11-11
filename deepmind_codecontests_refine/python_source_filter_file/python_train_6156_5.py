n=int(input())
s=input()
x=[]
ans=0
for i in range(1,n):
    a=s[i]
    if (a != s[i-1]):
        x.append(i)
p = x[0]
q = x[-1]-1

if(s[0]==s[-1]):
    ans = p + (n - q - 1) + (p * (n - q - 1)) + 1
else:
    ans=p+n-q-1+1
    ans = ans % 998244353
print(ans)

