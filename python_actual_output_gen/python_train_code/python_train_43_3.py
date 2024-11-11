n = int(input())
s = str(input())
arr = [i for i in s]
arr.sort()
t = "".join(arr)
if(s==t):
	print("NO")
else:
	print("YES")
	for i in range(n-1):
		if(s[i]>s[i+1]):
			print(i,i+1)
			break