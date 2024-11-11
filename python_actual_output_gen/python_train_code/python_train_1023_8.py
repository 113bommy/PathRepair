n = int(input())
out1 = ""
out2 = ""

for i in range(n):
    if i % 2 == 0:
        out1 += "w"
        out2 += "b"
    else:
        out1 += "b"
        out2 += "w"

for i in range(n):
    if i % 2 == 0:
        print(out1)
    else:
        print(out2)
