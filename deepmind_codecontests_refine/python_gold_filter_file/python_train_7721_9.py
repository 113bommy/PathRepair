import collections
import operator
nu=list(map(int,input().split(" ")))
n=nu[0]
m=nu[1]
ans=[]
for i in range(n):
	an=input()
	ans.append(an)
	
marks=list(map(int,input().split(" ")))
#print(ans)
#print(marks)
b=len(ans[0])

def add(temp):
	s=[]
	for i in range(0,len(temp)):
		s.append(temp[i][0])
	s1.append(s)
	
s1=[]
while(b!=0):
	add(ans)
	for i in range(len(ans)):
		ans[i]=ans[i][1:]
	b-=1
#print(s1)
mc=[]
for j in range(len(s1)):
	dd=dict(collections.Counter(s1[j]))
	mc.append(dd)
#print(mc)
for i in range(len(mc)):
	sorted_x = sorted(mc[i].items(), key=operator.itemgetter(1))
	mc[i]=sorted_x
#print(mc)
sum1=0
hh=0
for j in range(len(mc)):
	a=mc[j][len(mc[j])-1][1]
	#print(a,marks[hh])
	sum1+=a*marks[hh]
	hh+=1
print(sum1)

	
	
	

	



	
	
