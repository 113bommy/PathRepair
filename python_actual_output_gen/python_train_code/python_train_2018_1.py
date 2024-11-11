n = int(input())
s = input()
r = []
x = True
for v in s:
    if v == "(":
        r.append("r" if x else "b")
        x = not x
    elif v == ")":
        x = not x
        r.append("r" if x else "b")
print("".join(r))