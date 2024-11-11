import random
import sys
for i in range(int(input())):
	n,k=map(int,input().split())
	l=list(map(int,input().split()))
	K=1
	while(K<10**16+1):
		K*=k;
	
	
	kk=K
	while(kk>0):
		for j in range(n):

			if l[j]>=kk:
				print(kk)
					
				l[j]-=kk
				break
				

		kk//=k
	if sum(l)==0:
		print("YES")

	else:
		print("NO")
	


	
		