n = input()
x = input()
l = list(x)
c = 0
d = 0
for i in l:
    if i == 'x':
        c+=1 
    else:
        if c >= 3:
            d = c - 2
        c = 0
if c >= 3:
    d = c - 2
    c = 0        
print(d)