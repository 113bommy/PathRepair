s1 = input()
s2 = input()

if len(s1) != len(s2):
    a = sorted(list(s1))
    b = sorted(list(s2))
    # print(f"a = {a}")
    # print(f"b = {b}")
    automation = False
    i, j = 0, 0
    while i < len(a) and j < len(b):
        if a[i] == b[j]:
            j += 1
        i += 1
    if j == len(b):
        automation = True

    if automation:
        array = True
        i, j = 0, 0
        while i < len(s1) and j < len(s2):
            if s1[i] == s2[j]:
                j += 1
            i += 1
        if j == len(s2):
            array = False
        if array:
            print("both")
        else:
            print("automaton")
    else:
        print("need tree")

else:
    if sorted(list(s1)) == sorted(list(s2)):
        print("array")
    else:
        print("need tree")
