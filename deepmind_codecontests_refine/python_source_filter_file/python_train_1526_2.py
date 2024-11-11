n,a,b=map(int,input().split())

round=0
temp=n
while temp>1:
	round+=1
	temp//=2
max_round=round
if a>b:
	a,b=b,a
mid=n//2
while round>1:
	if a<=mid and b>mid:
		break
	round-=1
	n//=2
	mid+=n//2 if mid+n//2<=b else -n//2
print('Final!' if round==max_round else round)