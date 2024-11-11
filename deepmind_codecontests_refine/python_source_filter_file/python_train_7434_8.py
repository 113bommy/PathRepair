s=[int(n) for n in input().split()]
z=[int(n) for n in input().split()]
m=int(input())
if m<=s[0]:
	k=sum(z[:m])
else:
	k=((m-s[0])*s[1]-sum(z))*-1
print(k)