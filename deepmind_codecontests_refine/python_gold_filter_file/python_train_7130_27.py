n=int(input())
bar=['ABSINTH','BEER','BRANDY','CHAMPAGNE','GIN','RUM','SAKE','TEQUILA','VODKA','WHISKEY','WINE']
d=['0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17']
e=[]
for i in range(n):
	x=input()
	e.append(x)
z=0
for drink in e:
	if drink in bar:
		z+=1
	if drink in d:
		z+=1
	
print(z)
