s = input()
 
v = 0
h = 0
 
for c in s:
    if c == '0':
        v += 1
        print(1,v)
        v = v % 4
    elif c == '1':
        h += 1
        print(3,h*2-1)
        h = h%2