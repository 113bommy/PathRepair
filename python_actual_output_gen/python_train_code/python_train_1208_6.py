name_ip = {}
lst = []
n, m = map(int, input().split())

for i in range(n):
	name, ip = input().split()
	ip += ';'
	name_ip[ip] = name

for j in range(m):
	command, Cip = input().split()
	lst.append(command + Cip + '#' + name_ip[Cip])

for i in lst:
	print(i) 