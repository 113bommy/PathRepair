'''1dL1nG'''
a = input()
b = input()
al, bl = len(a), len(b)
l = min(al, bl)
c = 0
for i in range(l):
    if al % (i+1) == 0 and bl % (i+1) == 0:
        if a[:i+1]*(al//(i+1)) == a and b[:i+1]*(bl//(i+1)) == b:
            c += 1
print(c)
