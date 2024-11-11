n, x = map(int, input().split())
set1 = set(map(int, input().split()))
'''
if x == 0 and x in set1:
	for e in set1:
		print(e)
		break
else:
'''
set2 = set()
for i in range(0, x + 1):
	set2.add(i)

set3 = set2 - set1
print(set1)
print(set2)
print(set3)
if x in set3:
	#print(1)
	print(len(set3) - 1)
elif bool(set3) and x not in set3:
	#print(2)
	print(len(set3) + 1)
else:
	#print(3)
	print(len(set3) + 1)