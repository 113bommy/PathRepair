x = int(input())
a = input()
d = {"a","e","i","o","u"}
for i in range(x):
	if i == 0:
		print(a[i],end="")
		continue
	elif a[i] in d:
		if a[i-1] in d:
			continue
		else:
			print(a[i],end="")
	else:
		print(a[i],end="")