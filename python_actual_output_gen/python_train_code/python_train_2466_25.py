n=int(input())
l=[]
for i in range(n):
    l.append(input())
a=['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
for i in range(1,19):
    a.append(str(i))
c=0
for i in range(n):
    if l[i] in a:
        c=c+1
print(c)