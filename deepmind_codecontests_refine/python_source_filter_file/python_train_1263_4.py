b, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]

amods = [e % 2 for e in a]
#print(amods)

if b % 2 == 1:
    print("even" if sum(amods) % 2 == 0 else "odd")
else:
    print("even" if len(a) % 2 == 0 else "odd")