alcohol_drinks = ["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA",
                  "WHISKEY", "WINE"]
n = int(input())
count = 0
for i in range(0,n):
    var = input()
    if var[0].isupper():
        for alcohol_drink in alcohol_drinks:
            if alcohol_drink == var:
                count += 1
    else:
        if int(var) < 18:
            count += 1
print(count)






