n = input()
b=n.find('at', 1)
n= n[:b]+ '@' + n[b+2:]

b=n.find('dot', 1)

while 1 < b < len(n) - 3:
    n = n[:b] + '.' + n[b+3:]
    b = n.find('dot', b+1)
    
print(n)
