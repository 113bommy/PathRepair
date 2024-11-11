n,v = map(int,input().split())

req=0
i=2
if(n<v) :
	req+=n
	n=1
else :
	req+=v
	n=n-v

while(n>1) :
	n=n-1
	req+=i
	i=i+1

print(req)