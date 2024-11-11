n = input()
s = input()
a = s.split('W')
lst = []
for x in a:
    if len(x) > 0:
        lst.append(x)

print(len(lst))
for y in lst:
    print(y, end=' ')
