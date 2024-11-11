drinks = ["ABSINTH" , "BEER","BRANDY","CHAMPAGNE","GIN","RUM","SAKE","TEQUILA","VODKA","WHISKEY"]
n = int(input())
k=0;
for i in range(n):
	a = input()
	if a in drinks:
		k=k+1
		continue
	if 49<=ord(a[0])<=59:
		if int(a)<18:
			k=k+1	
print(k)
