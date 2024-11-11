# from sys import stdin,stdout
# input = stdin.readline

s=input()
h=[]
for i in range(len(s)):
	h.append([-1]*26)

i=len(s)-2
h[-1][ord(s[-1])-97]=len(s)-1
while(i>=0):
	for j in range(26):
		h[i][j]=h[i+1][j]
	h[i][ord(s[i])-97]=i
	i-=1

# print(h)
q=int(input())
for i in range(q):
	x,y=map(int,input().split())
	x-=1
	y-=1
	if(y-x==0):
		print("Yes")
	elif(s[x]!=s[y]):
		print("Yes")
	else:
		c=0
		for j in range(26):
			if(-1<h[x][j]<=y):
				c+=1
		if(c>2):
			print("Yes")
		else:
			print("No")