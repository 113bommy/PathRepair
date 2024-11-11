key = input()
n = int(input())

keys = []
for i in range(0,n):
    keys.append(input())
    
ok = True

if (keys[0] == key):
    ok = False

for i in keys:
    for j in keys:
        if (i != j and i == key or i == key[::-1] or (i[1] == key[0] and j[0] == key[1])):
            ok = False


if (ok == True):
    print ("NO")
else:
    print ("YES")
        
