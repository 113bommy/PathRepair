s = input()
index = {}
for l in s :
    if l in index:
        index[l] += 1
    else:
        index[l] = 1

if 'a' in index:
    index['a'] //= 2
if 'u' in index:
    index['u'] //= 2

min = 1000000
for l in ['B','u','l','b','a','s','u','r']:
    if l in index:
        new_min = index['l']
        if new_min< min:
            min = new_min
    else:
        min = 0 
        break

print (min)
    