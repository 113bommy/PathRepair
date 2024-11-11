# your code goes here

n = int(input())
res = set()
s = input().split()

for i in s:
	res.add(''.join(sorted(set(list(i)))))
	
print(len(res))