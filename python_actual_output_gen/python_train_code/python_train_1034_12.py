x = int(input())
y = input()

i = len(y)
while i > 0:
    i = i - 1
    if ("og"*i + "o") in y:
        y = y.replace(("og"*i + "o"), "***")
        
print(y)    