X = input()
X=X.split()
x = int(X[0])
y = int(X[1])
l = []
m = x % ((y*2)+1)
if m == 0 or m > y:
    i=y
else:
    # m 1 y 2
    i=y-((y+1)-m)
total = 0
while i <= x:
    l.append(str(i+1))
    i+=y*2+1
    total+=1
print(total)
s=' '.join(l)
print(s)
