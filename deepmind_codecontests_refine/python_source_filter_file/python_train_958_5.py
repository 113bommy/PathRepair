n = list(input())
m = input()

if len(n) > 1:

	n.sort()
	temp =''
	i = 0

	while n[i] == '0':
		temp += n[i]
		i += 1

	ans = n[i]+temp
	ans += ''.join(n[i+1:])
else:
	ans = n

#print(ans)
if ans == m :
	print("OK")
else:
	print("WRONG_ANSWER")