n=int(input())
a=input()
can=False
for i in range(n-1):
	if a[i]!=a[i+1]:
		can=True
		ans=a[i:i+2]
		break
if can:
	print("YES")
	print(ans)
else:
	print("NO")
