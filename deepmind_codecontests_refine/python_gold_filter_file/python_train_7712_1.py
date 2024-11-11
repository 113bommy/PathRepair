# your code goes here
from itertools import accumulate
n = int(input())
bi = 0

i = 0
j = n-1

a = list(map(int, input().split()))
li = list(accumulate(a))
lj = list(accumulate(a[::-1]))[::-1]

while i<j:
	
	if li[i]==lj[j]:
		bi = li[i]
		i+=1
		j-=1
	elif li[i]<lj[j]:
		i+=1
	elif lj[j] < li[i]:
		j-=1
		
print(bi)
	