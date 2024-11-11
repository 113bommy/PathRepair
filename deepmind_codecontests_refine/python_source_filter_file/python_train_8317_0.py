ls = []

def add(t):
    if t not in ls:
        ls.append(t)

n = int(input())
for i in range(n):
    t = input()[:-1]
    ls = [t] 
    for j in range(1,len(t)):
        f, b = t[:j], t[j:]
        add(f+b[::-1])
        add(f[::-1]+b)
        add(f[::-1]+b[::-1])
        add(b+f)
        add(b+f[::-1])
        add(b[::-1]+f)
        add(b[::-1]+f[::-1])
    print(len(ls))