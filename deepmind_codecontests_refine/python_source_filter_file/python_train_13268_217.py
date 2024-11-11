n = int(input())
l = []
for i in range(n):
    s = input()
    a = s.split()[0]
    b = s.split()[1]
    l.append(a)
    l.append(b)
nb =0
for i in range(0, len(l)-1, 2):

    r = (int(l[i+1]) - int(l[i]))
    if r > 2:
        nb += 1
print(nb)