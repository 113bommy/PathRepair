s = input()
L = len(s)
nA = L - s.count("a")
A = L - nA
D = nA - A + 1 #number of remove
res = L - D
if A < nA:
    print(res)
else:
    print(L)