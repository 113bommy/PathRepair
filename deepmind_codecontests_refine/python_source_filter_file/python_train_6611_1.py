n, m = input().split()
n = int(n)
m = int(m)

temp_f = input().split()
temp_b = input().split()
f, b, fff = dict(), dict(), dict()
amb = False
imp = False

for t, word in enumerate(temp_f):
    f[word] = (t+1, f.get(word, (0, 0))[1] + 1)
    fff[word] = fff.get(word, 0) + 1

for word in temp_b:
    b[word] = b.get(word, 0) + 1
    if word not in fff:
        imp = True
        break
    if b[word] > 1:
        amb = True


if imp:
    print("Impossible")
elif amb:
    print("Ambiguity")
else:
    print("Possible")
    for word in temp_b:
        print(f[word][0], end=" ")
    print("")


