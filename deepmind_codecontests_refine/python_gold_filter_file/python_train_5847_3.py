n = int(input().split()[0])
s = list(map(str, input()))

res = ""
blue = 0
red = 0
for el in s:
    if el == "(":
        if red > blue:
            blue += 1
            res += "1"
        else:
            red += 1
            res += "0"
    elif el == ")":
        if red > blue:
            red -= 1
            res += "0"
        else:
            blue -= 1
            res += "1"


print(res)