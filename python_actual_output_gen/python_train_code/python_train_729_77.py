n = int(input())
string = input()
l = -string.count("L")
b = string.count("R")
if l == 0:
    print(b)
elif b == 0:
    print(abs(l))
else:
    print(abs(l)+b+1)
