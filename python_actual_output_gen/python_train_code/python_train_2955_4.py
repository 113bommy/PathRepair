import sys

x = int(sys.stdin.readline())
a = sys.stdin.readline()
mp = ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]

found = False
st = ""
for m in range(len(mp)):
    if len(mp[m]) == len(a):
        ok = True
        for i in range(len(a)):
            if a[i] is '.':
                continue
            if a[i] != mp[m][i]:
                ok = False
                break

        if ok is True:
            st = mp[m]
            found = True

    if found is True:
        break

print(st)
