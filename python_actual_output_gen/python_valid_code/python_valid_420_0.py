n=int(input())
a= (list(map(int,input().split())))
sm1=sm2=0
cnt1=cnt2=0
for i ,num in enumerate(a):
	sm1+=num
	if sm1<=0 and i%2==0:
		cnt1+=1-sm1
		sm1=1
	elif sm1>=0 and i%2!=0:
		cnt1+=1+sm1
		sm1=-1
		
	sm2+=num
	if sm2<=0 and i%2!=0:
		cnt2+=1-sm2
		sm2=1
	elif sm2>=0 and i%2==0:
		cnt2+=1+sm2
		sm2=-1
	print(min(cnt1,cnt2))