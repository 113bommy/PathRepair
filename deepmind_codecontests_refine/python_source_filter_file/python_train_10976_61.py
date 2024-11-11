from sys import stdin as cin
from math import factorial as f
n,k= map(int,(cin.readline().split()))
a = list(map(int,(cin.readline().split())))
a.sort()
print(a)
count = 0
tmp = 0
for x in a:

	if 5-x-k>=0:
		tmp+=1
		flag = 1
	else:
		flag = 0

	if tmp%3 == 0 and flag==1:
		tmp = 0
		count+=1
	#print(tmp,5-x-k,count)
print(count)