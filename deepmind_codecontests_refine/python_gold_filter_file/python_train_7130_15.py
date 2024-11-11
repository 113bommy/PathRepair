forbid = "ABSINTH, BEER, BRANDY, CHAMPAGNE, GIN, RUM, SAKE, TEQUILA, VODKA, WHISKEY, WINE".split(", ")
n = int(input())
a = []
for i in range(n):
    x = input()
    if x.isnumeric():
        if int(x) < 18:
            a.append(x)
    
    if x.isalpha():
        if x in forbid:
            a.append(x)

print(len(a))