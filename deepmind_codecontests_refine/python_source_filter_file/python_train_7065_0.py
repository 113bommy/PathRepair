a = 0
b = 0
o = 0
ab = 0
while True:
    try:
        n, bt = input().split(",")
        if bt =="A":
            a += 1
        elif bt =="B":
            b += 1
        elif bt =="O":
            o += 1
        elif bt =="AB":
            ab += 1
    except:
        break
print(a, b, o, ab, sep="\n")

