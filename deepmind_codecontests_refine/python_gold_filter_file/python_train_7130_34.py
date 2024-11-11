n = int(input())
a = 0
alco = ["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"]
for i in range(n):
    s = input()
    if (s[0] in '0123456789'):
        if (int(s) < 18): a += 1
    else:
        if (s in alco): a += 1
print(a)