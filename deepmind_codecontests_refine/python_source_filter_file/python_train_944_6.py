
def mi():
	return map(int, input().split())

n = int(input())

old = [0]*n
new = [0]*n

for i in range(n):
	old[i] = input()
for i in range(n):
	new[i] = input()


old.sort()
new.sort()
cnt = 0
i = 0

while i<len(old):
	if old[i] in new:
		del(new[new.index(old[i])])
		del(old[i])
	i+=1
for i in range(len(old)):
	old[i] = sorted(list(old[i]))
	new[i] = sorted(list(new[i]))
	for j in range(len(old[i])):
		if old[i][j]!=new[i][j]:
			cnt+=1
print (cnt)