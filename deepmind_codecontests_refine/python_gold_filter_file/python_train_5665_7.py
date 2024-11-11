def watermelon():
	n=int(input())
	if n>3 and n%2==0:
		print("YES")
	else:
		print("NO")


def way_to_long():
	for _ in range(int(input())):
		s=input()
		if len(s)>10:
			print(s[0]+str(len(s)-2)+s[-1])
		else:
			print(s)

def marks():
	n,m=map(int,input().split())
	arr=[]
	for _ in range(n):
		arr.append(input())
	cnt=0
	for i in range(n):	
		for j in range(m):
			sub=arr[i][j]
			for k in range(n):
				if arr[k][j]>sub:
					break
			else:
				cnt+=1
				break
	print(cnt)
	

def c_strings():
	s=input()
	t=input()
	i=0
	j=0
	cnt=1
	while i<len(s) and j<len(t):
		if s[i]==t[j]:
			cnt+=1
			i+=1
			j+=1
		else:
			j+=1

	print(cnt)


def domino():
	n=int(input())
	du=0
	dl=0
	cnt=0
	for i in range(n):
		x,y=map(int,input().split())
		if (x%2!=0 and y%2==0) or (x%2==0 and y%2!=0):
			cnt+=1
		du+=x
		dl+=y

	if du%2==0 and dl%2==0:
		print(0)
	elif (du%2==0 and dl%2!=0) or (du%2!=0 and dl%2==0):
		print(-1)
	else:
		if cnt>1:
			print(1)
		else:
			print(-1)



if __name__ == '__main__':
	domino()
