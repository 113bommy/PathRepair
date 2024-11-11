n=int(input())
T=input()
d={0:-1}
s=0
mix=0
 
for i in range(n):
	if(T[i]=='0'):
		s+=-1
	else :
		s+=1
		if s not in d:
			d[s]=i
		else:
			if(i-d[s])> mix:
				mix=i-d[s]
print(mix)