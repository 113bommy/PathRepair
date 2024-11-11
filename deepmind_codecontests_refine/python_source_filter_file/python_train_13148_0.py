from sys import stdin,stdout

t=int(input())
for _ in range(t):
	n,u,v=map(int,stdin.readline().split())
	arr=list(map(int,stdin.readline().split()))
	flag=False
	for i in range(1,n):
		if(abs(arr[i]-arr[i-1])>1):
			flag=True
			break
	if(flag):
		stdout.write("0\n")
	else:
		flag2=False
		for i in range(1,n):
			if(abs(arr[i]-arr[i-1])>0):
				flag2=True
				break
		if(flag2):
			ans=min(u,v)
			stdout.write(str(ans)+"\n")
		else:
			ans=u+v
			stdout.write(str(ans)+"\n")