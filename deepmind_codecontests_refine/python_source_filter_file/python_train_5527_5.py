n, m = map(int,input().split())
a = list(map(int,input().split()))
a = [0] + a + [m]
temp = 1
b = [0]*len(a)
for i in range(0,len(a),2):
	b[i]=1
#print(a)
#print(b)
b[len(a)-1] = 0
#print(b)
ot = 0
for i in range(len(a)):
	if b[i]==0 and b[i-1]==1:
		ot += a[i] - a[i-1]
print(ot)
tmp2 = 0
tmp1 = ot
ans = ot
for i in range(len(a)-1,0,-1):
	if b[i-1]==0:
		if a[i]-a[i-1]>1:
			tmp2 +=a[i]-a[i-1]-1
			ans=max(ans,tmp1+tmp2)
			tmp2+=1
		else:
			tmp2+=1
	elif b[i-1]==1:
		tmp1-=a[i]-a[i-1]
	#print(tmp1,tmp2,ot,ans)
print(ans)