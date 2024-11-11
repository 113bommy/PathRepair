def swaping(z, w, e):
    temp = z[e]

    z[e] = z[w]
    z[w] = temp
    return z


q = int(input())
qwerty = input()
p = [int(i) for i in qwerty.split(" ")]
i = 0
while i < q - i + 1:
    p = swaping(p, i, q - i -1)

    i += 2




for i in p:
    print("{} ".format(i))
