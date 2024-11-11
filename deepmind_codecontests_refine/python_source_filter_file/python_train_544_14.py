t = int(input())
for i in range(t):
    z = 0
    s = input()
    for c in s:
        if c == '0':
            z += 1
    w = min(z , len(s) - z)
    print("NET" if z%2==0 else "DA")