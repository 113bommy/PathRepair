s = input()
L = len(s)
A = s.count("a")
nA = L - A
D = nA - A + 1 #number of remove
res = L - D
if A <= nA:
    print(res)
else:
    print(L)