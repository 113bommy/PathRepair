m=int(input())
cnt=0
cnt1=0
for i in range(m):
	m,n=map(int,input().split())
	if m>0:
		cnt+=1
	if m<0:
		cnt1+=1
if cnt==m or cnt==m-1 or cnt==0 or cnt==1:
	print("Yes")
else:
	print("No")
