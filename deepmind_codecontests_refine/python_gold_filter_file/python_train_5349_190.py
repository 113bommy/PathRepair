userinput = input()
userlist = list(userinput)
i = 1
n = len(userlist) - 1
output = userinput[0].upper()
while i <= n:
	output = output + userlist[i]
	i += 1
print(output)