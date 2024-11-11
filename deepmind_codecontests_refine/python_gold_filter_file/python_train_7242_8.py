s = input()
lst = []
B = s.count('B')
lst.append(B)
u = s.count('u')
l = s.count('l')
lst.append(l)
b = s.count('b')
lst.append(b)
a = s.count('a')
ss = s.count('s')
lst.append(ss)
r = s.count("r")
lst.append(r)
a = a // 2
lst.append(a)
u = u // 2
lst.append(u)
print(min(lst))
