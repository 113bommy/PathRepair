s = input()
t = input()
a = b = {}
for c, d in zip(s, t) :
    if a.setdefault(c, d) != d : print("No") ; break
    if b.setdefault(d, c) != c : print("No") ; break
else : print("Yes")