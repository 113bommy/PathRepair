a = input()
x = a[0]
out = []
for el in a:
    if x < el:
        out.append("Ann\n")
    else:
        out.append("Mike\n")
        x = el
print(out)
