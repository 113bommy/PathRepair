t,s=int(input()),""
while t>0 :
	t-=1
	a,b,c=map(int,input().split())
	ans=4*10**4
	p=[0]*3
	for i in range(1,10**4+1) :
		cur=[i]+[0]*2
		for j in range(i,10**4+1,i) :
			cur[1]=j
			cur[2]=c-c%j if c%j*2<j and c-c%j>=j else c-c%j+j
			cost=abs(cur[0]-a)+abs(cur[1]-b)+abs(cur[2]-c)
			if(cost<ans) :
				ans=cost
				p=cur.copy()
	s+=str(ans)+"\n"
	for i in range(3) :
		s+=str(p[i])+" "
	s+="\n"
print(s)