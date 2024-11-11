p1,p2,p3,p4,a,b = map(int,input().split())
from itertools import permutations
t = list(permutations([p1,p2,p3,p4]))
print(t)
i = a
count = 0
t1 = 0
while i <= b:
	count = 0
	for j in t:
		if ((((i%j[0])%j[1])%j[2])%j[3]) == i:
			count = count + 1
	if count >= 7:
		t1 = t1 + 1
	i = i + 1
print(t1)