y = int(input())
r = y

while (str(r).count(str(r)[0]) != 1) or (str(r).count(str(r)[1]) != 1) or (str(r).count(str(r)[2]) != 1) or (str(r).count(str(r)[3]) != 1):
    r += 1

print(r)