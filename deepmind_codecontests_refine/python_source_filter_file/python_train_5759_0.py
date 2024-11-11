from sys import stdin as si , stdout as so

for _ in range(int(si.readline())):
    s = si.readline().strip()
    l = len(s)
    if s=="a":
        so.write("NO\n")
    else:
        f = False
        d = ""
        for i in range(l):
            if s[i]=='a':
                d += s[ : l-i+1] + "a" + s[l-i+1 : ]
                f = True
                break
        if f:
            so.write("YES\n")
            so.write(d + "\n")
        else:
            so.write("NO\n")