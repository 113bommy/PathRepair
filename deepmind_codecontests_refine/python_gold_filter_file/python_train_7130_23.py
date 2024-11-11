n = int(input())
d = ['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
k = 0
for _ in range(n):
    v = input()
    if (v.isdigit() and int(v) < 18) or (v.isalpha() and v in d):
        k += 1
print(k)