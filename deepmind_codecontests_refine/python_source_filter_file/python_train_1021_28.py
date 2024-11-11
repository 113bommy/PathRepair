
h,w=map(int,input().split())
a=["."*(w+2)]
for i in range(h):
	x=input()
	a.append("."+x+".")
a.append("."*(w+2)
for i in range(h):
	for j in range(w):
		if a[i+1][j+1]=="#":
			if a[i][j+1]=="#" or \
a[i+2][j+1]=="#" or a[i+1][j+2]=="#" or\
a[i+1][j]=="#":
				continue
			else:
				print("No")
				exit()
print("Yes")