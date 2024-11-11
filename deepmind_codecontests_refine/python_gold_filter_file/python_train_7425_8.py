runs = int(input())
directory = ['/']

for x in range(runs):
	command = input()
	first = command[0]
	if first == "p":
		print(''.join(directory))
	elif first == "c":
		address = command[3:].split("/")
		if not address[0]:
			directory = ["/"]
		for x in address:
			if x == "..":
				directory.pop()
			else:
				if x:
					directory.append(x+"/")

