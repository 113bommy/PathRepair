a,b,c,x=[int(input()) for i in range(4)]
cnt=0
for i in range(a):
	if 500*i>x:break
	for j in range(b):
		if 500*i+100*j>x:break
		if (x-500*i-100*j)<=50*c:cnt+=1
print(cnt)