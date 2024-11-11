n=int(input())
k=n
i=1
s=""
while n>i:
	n-=i
	if i>=n:
		s+=str(n+i)+" "
		break
	else:
		s+=str(i)+" "
	i+=1
if k==1:
       print(1)
       print(1)
else:
       print(i,s,sep="\n")