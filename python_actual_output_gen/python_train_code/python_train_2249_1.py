s = input()
if len(s) < 4:
    print(0)
a = 0
if len(s) >= 4:
    for i in range(len(s)):
        d = s.find('bear', i)
        if d >= 0:
            a += len(s) - d - 3
print(a)




