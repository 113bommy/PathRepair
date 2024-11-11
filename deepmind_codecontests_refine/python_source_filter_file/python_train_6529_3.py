import math as ma
from sys import exit
from decimal import Decimal as dec
def li():
	return list(map(int,input().split()))
def num():
	return map(int,input().split())
def nu():
	return int(input())
n,x,y=num()
s=input()
con=0
for ch in range(1,n):
	#print(s[ch],s[ch-1],s[ch]!=s[ch-1])
	if(s[ch]!=s[ch-1] and s[ch-1]=='0'):
		#print("Entered")
		con+=1
if(s[n-1]==0):
	con+=1
#print(con)
if(con==0):
	print(0)
	exit()
ans=min(x,y)*con+y
print(ans)
