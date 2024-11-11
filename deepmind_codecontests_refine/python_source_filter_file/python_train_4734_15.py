
t=list(input().split())
b=("a","e","i","o","u","A","E","I","O","U")
if len(t[-1])==1:
	if t[-2][-1] in b:
		print("YES")
	else:
		print("NO")
elif t[-1][-2] in b:
	print("YES")
else:
	print("NO") 