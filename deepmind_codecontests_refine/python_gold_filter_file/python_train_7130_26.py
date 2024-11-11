n = int(input())
count = 0

l = ['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
ll = [str(i) for i in range(10)]
for i in range(n):
	s = input()
	if s in l:
		count += 1
	elif s[0] in ll and int(s) < 18:
		count += 1
print (count)