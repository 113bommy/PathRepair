import sys
from sys import stdin,stdout
def findbestwithin(re):
	global cost
	s=-1;m1=re
	for i in range(len(cost)):
		if cost[i]<=m1 and i>s:
			s=i
	return s
def findminnumber():
	global cost
	s=-1;m1=sys.maxsize;co=cost
	for i in range(len(co)):
		if co[i]<m1 or(co[i]==m1 and i>s):
			s=i;m1=co[i]
	return s
m=int(input())
cost=list(map(int,input().split(' ')))
if min(cost)>m:
	print(-1)
else:
	d={}#Dictionary to store count of each digit
	t1=findminnumber()#Returns the minimum number in the List.
	t2=m//cost[t1]
	t3=m%cost[t1]#Money Left
	d[t1+1]=t2
	if t3==0:#If no money is left simply print.
		for i in d:
			for j in range(d[i]):
				stdout.write(str(i))
	else:#Try to greedily maximize each digit
		getbest=findbestwithin(cost[t1]+t3)#returns the greatest posssible number that can be selected within a given value. If none can be selected returns -1.
		while getbest!=-1:
			#print("Runs")
			if getbest>t1:
				t3=t3+cost[t1]-cost[getbest]
				if getbest+1 in d:
					d[getbest+1]+=1
				else:
					d[getbest+1]=1
				d[t1+1]-=1
			if getbest==t1:
				break
			getbest=findbestwithin(cost[t1]+t3)

		t4=list(d.keys());t4.sort();t4.reverse();
		for i in t4:
			for j in range(d[i]):
				stdout.write(str(i))