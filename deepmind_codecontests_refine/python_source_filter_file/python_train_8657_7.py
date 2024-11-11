n=int(input())
l=list(map(int,input().split()))
mp={}

for i in range(n):
	mp[l[i]]=i+1
l.sort()
def AP(l):
	if(len(l)==1):
		return True
	d=l[1]-l[0]
	for i in range(2,len(l)):
		if(d!=l[i]-l[i-1]):
			return False
	return True
if (n<=3):
	for i in range(n):
		if(AP(l[:i]+l[i+1:])):
			print(mp[l[i]])
			quit()
	print(-1)
else:
	dct={}
	D,cnt=-1,0
	for i in range(1,n):
		d=l[i]-l[i-1]
		if d in dct:
			dct[d]+=1
		else:
			dct[d]=1
	for i in dct:
		if dct[i]>cnt:
			D=i
			cnt=dct[i]
	for i in range(1,n):
		if(l[i]-l[i-1]!=D):
			if(AP(l[:i]+l[i+1:])):
				print(mp[l[i]])
			elif(AP(l[:i-1]+l[i:])):
				print(mp[l[i-1]])
			else:
				print(-1)
			break
	else:
		print(mp[l[0]])