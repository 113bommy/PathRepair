B = input()
order = True
F = ""
for q in range(int(input())):
    T = input().rstrip().split()
    if T[0] == "1":
        order ^= True
    else:
        f,c = T[1],T[2]
        if not((f == "1") ^ order):
            F += c
        else:
            B += c
    print(F,B)
F = F[::-1]+B
if not order:
    F = F[::-1]
print(F)