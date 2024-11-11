arr=[int(x) for x in input().split()]
w1=arr[0]
h1=arr[1]
w2=arr[2]
h2=arr[3]
if w1==w2:
	print((w1+2)*2+(h1+h2)*2)
else:
	print(w1+2+w2+2+h2+h1+1+h1+h2)
