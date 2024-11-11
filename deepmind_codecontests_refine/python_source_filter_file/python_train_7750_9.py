x = input()
lol = False
n = ''
s = ''
for letter in x:
    if letter == ' ':
        lol = True
    else:
        if lol == False:
            n += letter
        if lol == True:
            s += letter
lol = False
n = int(n)
s = 100*int(s)
change = ''
sugars = []
price = ''
changes = []
for i in range(n):
    sugar = input()
    for letter in sugar:
        if letter == ' ':
            lol = True
        else:
            if lol == False:
                price += letter
            if lol == True:
                change += letter
    sugars.append(100*int(price)+ int(change))
    lol = False
    change = ''
    price = ''
for item in sugars:
    if s > item:
        left = (item-1)%100
        right = 99-left
        changes.append(right)
if len(changes) == 0:
    ans = -1
else:
    ans = max(changes)
print(ans)