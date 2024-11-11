n = input().split(" ")
str = ""
new = []
b = {}
for i in range(int(n[1])):
    n1 = input().split(" ")
    b[n1[0]] = n1[1]
str = input().split(" ")
for k in str:
    if len(k) < len(b[k]):
        new.append(k)
    else:
        new.append(b[k])
new1 = ' '.join(new)
print(new1)