n = int(input())

l = list(map(int,input().split()))

l.sort()

i = 0
c = 0
stack = []
k = 1
i = 0
while i < n-1 and k < n:


	stack.append(l[i])
	if l[i] != l[i+1]:
		if k < i:
			k = i+1

		while k < n and len(stack):

			stack.pop()
			c = c + 1

			k = k + 1

	i = i + 1

print(c)