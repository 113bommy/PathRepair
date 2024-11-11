import sys

for line in sys.stdin:
    line = line.strip()
    i = 0
    ans = ""
    while i < len(line):
        if line[i] == "@":
            m = int(line[i+1])
            c = line[i+2]
            i += 3
            ans += m*c
        else:
            ans += line[i]
            i += 1
    print(ans)