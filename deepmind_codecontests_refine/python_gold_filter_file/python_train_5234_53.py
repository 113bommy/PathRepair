import sys
import math
from collections import defaultdict,Counter

input=sys.stdin.readline
def print(x):
    sys.stdout.write(str(x)+"\n")

# sys.stdout=open("CP2/output.txt",'w')
# sys.stdin=open("CP2/input.txt",'r')

# m=pow(10,9)+7
t=int(input())
for i in range(t):
	n,s=map(int,input().split())
	n1=str(n)
	ans=0
	ind=-2
	for j in range(len(n1)):
		ans+=int(n1[j])
		if ans==s and ind==-2:
			ind=j
		elif ans>s:
			if ind==-2:
				ind=j
				break
		# 	d=len(n1)-j
		# 	while prev==s:
		# 		d+=1
		# 	if prev==s:
		# 		d+=1
		# prev=ans
	if ans<=s:
		print(0)
		continue

	if ind==-1:
		ans1=pow(10,len(n1))-n
	else:
		ans1=pow(10,len(n1)-ind)-int(n1[ind:])
	print(ans1)
	# 	for j in range(ind+1,len(n1)):
	# 		ans1+=
	# while n1:
	# 	d=n1%10
	# 	ans+=d
	# 	n1//=10
	# 	if ans>s:
	# 		break
	# if ans<=s:
	# 	print(0)
	# 	continue
	# l1=len(str(n))
	# print(pow(10,l1)-n)