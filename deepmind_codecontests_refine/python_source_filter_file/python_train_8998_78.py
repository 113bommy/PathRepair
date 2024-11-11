def degree(s):
    t = "00" + s.rstrip()
    x = int(t[:-2])
    if x % 4 == 0:
        return "0"
    return "4"


n = int(input())
print(degree(str(n)))
