n=int(input())
c2=0
c4=0
for a in map(int,input().split()):
	if a%4==0:c4+=1
	elif a%2==0:c2+=1
if c2>1:n-=c2
print('Yes' if c4>=n//2 else 'No')
	