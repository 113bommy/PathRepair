a = input()
count = 0
lt = ['ABSINTH','BEER','BRANDY','CHAMPAGNE','GIN','RUM','SAKE','TEQUILA','VODKA','WHISKEY','WINE']
lst = list()
for i in range(int(a)):
    b = input()
    try:
        c = int(b)
        if c < 18:
            count = count + 1
    except:
        lst.append(b)
for d in lst:
    if d in lt:
        count = count + 1
print(count)