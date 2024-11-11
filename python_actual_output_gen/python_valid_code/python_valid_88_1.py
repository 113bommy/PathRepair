s=list(map(int,input()))
n=len(s)
mod=1000000007
left=(n*(n-1)//2)%mod
right=0
out=0
fact=1
for i in range(n):
	out=(out+right*s[n-i-1])%mod
	out=(out+left*fact*s[n-i-1])%mod
	right=(right+(i+1)*fact)%mod
	left=(left-n-i-1)%mod
	fact=fact*10%mod
print(out%mod)