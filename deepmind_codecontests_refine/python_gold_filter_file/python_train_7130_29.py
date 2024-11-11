x,y=0,0
p="ABSINTH, BEER, BRANDY, CHAMPAGNE, GIN, RUM, SAKE, TEQUILA, VODKA, WHISKEY, WINE"
p=p.split(", ")
for ctr in range(int(input())):
    a=input()
    if a.isdigit():
        if int(a)<18:
            x+=1
    else:
        if a in p:
            x+=1
print(x)
