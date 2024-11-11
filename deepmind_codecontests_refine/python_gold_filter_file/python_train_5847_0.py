n = int(input())
s = input()
r = []
x = True
for v in s:
    if v == "(":
        r.append("0" if x else "1")
        x = not x
    elif v == ")":
        x = not x
        r.append("0" if x else "1")
print("".join(r))