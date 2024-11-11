w = input()
a = input()
b = input()
v = n = 0

if (w.find(a)!=-1 and w.find(a) < w.rfind(b)-len(b)):
    v = 1
w = w[::-1]
if (w.find(a)!=-1 and w.find(a) < w.rfind(b)-len(b)):
    n = 1
if v and n:
    print("both")
elif v:
    print("forward")
elif n:
    print("backward")
else:
    print("fantasy")
