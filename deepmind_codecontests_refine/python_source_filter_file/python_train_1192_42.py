key = "qwertyuioppaasdfghjkl;;zzxcvbnm,./"
d = input()
m = input()
x = 1
if d == 'R':
    x = -1
for each in m:
    i = key.index(each)
    print(key[i + x], end="")