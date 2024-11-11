a = input().split()
b = []
for i in a:
    if i.isdigit():
        b.append(i)
    else:
        c = b.pop()
        d = b.pop()
        ans = eval(str(d)+i+str(c))
        b.append(ans)
print(b)

