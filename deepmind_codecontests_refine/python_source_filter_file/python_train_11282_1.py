S = input ()
T = input ()

liss_pos = 0
for i in range (len(T)):
    if T[i] == S[liss_pos]:
        liss_pos += 1

print(liss_pos)