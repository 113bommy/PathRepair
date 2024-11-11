s = input()

l = []
for i in s:
    l.append(ord(i) - 97)

print(l)
y = True
k = -1
for i in range(len(l)):
    if l[i] - k > 1:
        y = False
        break
    else:
        k = max(l[i], k)

if y:
    print("YES")
else:
    print("NO")