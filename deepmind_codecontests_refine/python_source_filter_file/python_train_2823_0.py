# https://codeforces.com/contest/106/problem/A

trump = input()
c1, c2 = input().split()

cs = ['6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A']
def find(x):
    for i in range(0, len(cs)):
        if cs[i] == x:
            return i

if trump in c1 and trump in c2:
    c1x = find(c1[0])
    c2x = find(c2[0])
    if c1x > c2x:
        print("YES")
    else:
        print("No")
elif trump in c1:
    print("YES")
elif trump in c2:
    print("NO")
else:
    if c1[1] != c2[1]:
        print("NO")
    else:
        c1x = find(c1[0])
        c2x = find(c2[0])
        if c1x > c2x:
            print("YES")
        else:
            print("No")
