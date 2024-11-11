from math import ceil
t = int(input())
for _ in range(t):
    n = int(input())
    if n>1:
        a = [1]
        for i in range(2,ceil(n**0.5+1)):
            if i**2<=n:
                a.append(i**2)
            if i**3<=n:
                a.append(i**3)
        print(len(a))
    else:
        print(1)
