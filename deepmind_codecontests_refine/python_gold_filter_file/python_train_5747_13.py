n = int(input())
ans = n
if n == 1:
	print(1)
	exit()
facts = []
while n%2 == 0:
	facts.append(2)
	n = n//2
for i in range(3, int(n**0.5)+1, 2):
	while n%i == 0:
		n = n//i
		facts.append(i)
if n != 1:
	facts.append(n)
if facts[-1] == ans:
	print(ans)
elif len(set(facts)) == 1:
	print(facts[0])
else:
	print(1)