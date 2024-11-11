h,w=map(int,input().split())
slis=[]
a=["."]*(w+2)
slis.append(a)
for i in range(h):
	s=list("."+input()+".")
	slis.append(s)
slis.append(a)
for i in range(1,h+1):
	for j in range(1,w+1):
		a=slis[i-1][j-1:j+2]+slis[i][j-1:j+2]+slis[i+1][j-1:j+2]
		if slis[i][j] != "#":
			slis[i][j]=a.count("#")
for i in range(1,h+1):
	print(*slis[i][1:w+1])