n=int(input())
s='aabbc'
L=n%5
red=s[0:L]
time=n//5
ans=''
for _ in range(time):
    ans+=s
ans+=red
print(ans)