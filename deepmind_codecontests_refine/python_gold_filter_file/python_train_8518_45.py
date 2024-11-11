S = input()

T = list("AKIHABARA")

spos = 0

for i, t in enumerate(T):
    if spos < len(S) and S[spos] == t:
        spos += 1
    elif t == "A":
        continue
    else:
        print("NO")
        exit()

print("YES" if spos == len(S) else "NO")
