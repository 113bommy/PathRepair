n = int(input())

lib = {}
idL = 0
idR = -1
for i in range(n):
    masukan = input().split(" ")
    if masukan[0] == "L":
        idL = idL - 1
        lib[masukan[1]] = idL
    elif masukan[0] == "R":
        idR = idR + 1
        lib[masukan[1]] = idR
    else:
        idx = lib[masukan[1]]
        idxx = idx+abs(idL)
        print(min(idxx, abs(idR+abs(idL)-idxx)))