l=['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
s='0123456789'
c=0
for i in range(int(input())):

    n=input()
    if n[-1] not in s:
        if n not in l:
            c+=1
    if n[-1] in s:
        if int(n)<18:
            c+=1
print(c)