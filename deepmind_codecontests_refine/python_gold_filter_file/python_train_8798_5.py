n = int(input())
l = []

for _ in range(n):
	l.append(input())

answer = []
s = set()

for i in range(n - 1, -1, -1):
	if l[i] not in s:
	  s.add(l[i])
	  answer.append(l[i])

for _ in answer:
  print(_)