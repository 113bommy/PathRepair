n,k=map(int,input().split());l=sorted(list(map(int,input().split())));c=0
a=l[0]-1 if k==0 else l[k-1]
for i in l:
	if a>=i :
		c+=1 	
print(a if c==k and a>0 else -1)