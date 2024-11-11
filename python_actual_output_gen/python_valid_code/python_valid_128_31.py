
t=input()
a=("H","Q","9","+")
b=0
for i in range(len(a)):
	if a[i] in t:
		b=1
		print("YES")
		break
if b==0:
	print("NO")