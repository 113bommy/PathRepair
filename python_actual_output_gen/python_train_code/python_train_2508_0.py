from sys import stdin
s = stdin.readline()[:-1]
val_dict = {}
t = 'Bulbbasaur'
for i in s:
    if i in t:
        if i in val_dict:
            val_dict[i] += 1
        else:
            val_dict[i] = 1
not_found = True
ans = 0
while not_found:
    for i in t:
        if i in val_dict:
            val_dict[i] -= 1
            if val_dict[i] == 0:
                del val_dict[i]
        else:
            not_found = False
            break
    if not not_found:
        break
    ans += 1
print(ans)
