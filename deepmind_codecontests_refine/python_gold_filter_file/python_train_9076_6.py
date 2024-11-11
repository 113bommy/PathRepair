from sys import stdin
from math import *

for i in range(int(input())):
	s=input()
	ans=""
	i=0
	j=0
	while(i<len(s) and j<len(s)):
		while(j<len(s)):
			if(s[i]!=s[j]):
				if((j-i)%2!=0):
					if(s[i] not in ans):
						ans+=s[i]
				i=j
				j+=1
			else:
				j+=1
	if((j-i)%2==1):
		if(s[i] not in ans):
			ans+=s[i]
	ans=list(ans)
	ans.sort()
	print("".join(ans))