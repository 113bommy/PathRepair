import sys
input=sys.stdin.readline
n=int(input())
BIT=[[0]*n for i in range(26)]
w=[ord(x)-ord("a") for x in input()]
for i in range(n):
	k=i+1
	while k<=n:
		BIT[w[i]][k-1]+=1
		k=k+(k&-k)
q=int(input())
for i in range(q):
	a,b,c=input().split()
	if a=="1":
		k=int(b)
		while k<=n:
			BIT[ord(c)-ord("a")][k-1]+=1
			k=k+(k&-k)
		k=int(b)
		while k<=n:
			BIT[w[int(b)-1]][k-1]-=1
			k=k+(k&-k)	
		w[int(b)-1]=ord(c)-ord("a")
	else:
		b=int(b);c=int(c)
		ans=0
		for i in range(26):
			cnt=0
			k=c
			while k!=0:
				cnt+=BIT[i][k-1]
				k=k-(k&-k)
			k=b-1
			while k!=0:
				cnt-=BIT[i][k-1]
				k=k-(k&-k)
			if cnt>0:
				ans+=1
		print(ans)