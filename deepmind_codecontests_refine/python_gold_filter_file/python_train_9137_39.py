N,P=map(int,input().split());S,a,i,j,c=list(map(int,input())),0,0,1,[1]+[0]*P
if 10%P:
	for v in S[::-1]:i=(i+v*j)%P;j=j*10%P;a+=c[i];c[i]+=1
else:
	for i,v in enumerate(S):
		if v%P<1:a+=i+1
print(a)