D = {"a":0, "b":1, "c":2}
l = ["A", "B", "C"]
 
x = [[D[a] for a in input()] for _ in range(len(l))]
c = 0
while x[c]:
    c = x[c].pop(0)
print(I[c])