s = input()
l = len(s)
l2 = int(len(s)/2)
g = s.count("a")
if g > l2:
    print(l)
else:
    a = l2-g
    print(a)
