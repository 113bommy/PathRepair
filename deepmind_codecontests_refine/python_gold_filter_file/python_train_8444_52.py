a = input().split(' ')
y = int(a[0])
b = int(a[1])
r = int(a[2])

for i in range(2):
    if y >= b:
        y = b - 1
    
    if r > b:
        r = b + 1
        
    if b >= r:
        b = r - 1
        
    if b > y:
        b = y + 1
    
print(y+b+r)