l = ['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
n = int(input())
x = 0
for i in range(n):
    s = input()
    if ((s.isdigit() and int(s) > 18) or s in l):
        x += 1
print(x)