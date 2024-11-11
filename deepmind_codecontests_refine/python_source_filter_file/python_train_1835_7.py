n = input()
s = str()
a = set()
res = 0
for i in s:
    if i.islower():
        a.add(i)
        res = max(res,len(a))
    else:
        a.clear()
print(res)