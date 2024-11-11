a = input()
rez = 'aeiou02468'
r = 0
for i in a:
    if i in rez:
        r += 1
print(r)