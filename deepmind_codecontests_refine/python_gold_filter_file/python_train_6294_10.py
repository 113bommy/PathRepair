n1 = input()
n2 = input()
n3 = input()

if n1[1] == ">":
    n1 = n1[2] + "<" + n1[0]
if n2[1] == ">":
    n2 = n2[2] + "<" + n2[0]
if n3[1] == ">":
    n3 = n3[2] + "<" + n3[0]

if n1[0] != n2[0] and n1[0] != n3[0] and n3[0] != n2[0]:
    print("Impossible")
elif n1[0] == n2[0]:
    print(n1[0], n3[0], n3[2], sep ="")
elif n1[0] == n3[0]:
    print(n1[0], n2[0], n2[2], sep ="")
elif n3[0] == n2[0]:
    print(n3[0], n1[0], n1[2], sep ="")