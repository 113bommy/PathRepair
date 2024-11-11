
t = input()
c = input()

liss_pos = 0

for a in range(len(t)):
    if t[a] == c[liss_pos]:
        liss_pos += 1

print(liss_pos + 1)