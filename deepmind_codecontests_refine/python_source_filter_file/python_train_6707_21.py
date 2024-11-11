s = input()
n = s.count('n')
i = s.count('i')
e = s.count('e')
t = s.count('t')
if n >= 5:
    num = min(int(e/3),int(i),int(t),int((n+1)/3))
else:
    num = min(int(e/3),int(i),int(t),int((n)/3))
print(num)
