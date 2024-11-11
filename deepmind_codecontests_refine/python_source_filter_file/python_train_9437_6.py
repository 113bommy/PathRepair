str = input()
occs = [0] * 26
for c in str:
    occs[ord(c) - ord('a')] += 1

occs = [x for x in list(sorted(occs)) if x != 0]

if len(occs) == 1:
    print("No")
elif len(occs) == 2:
    if occs[0] > 1:
        print("Yes")
    else:
        print("No")
elif len(occs) == 3:
    if occs[1] > 1:
        print("Yes")
    else:
        print("No")
elif len(occs) == 4:
    print("Yes")
else:
    print("No")
