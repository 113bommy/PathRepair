n = int(input())
flag = False
out = ""
for i in range(n):
    txt = input()
    if not flag:
        if txt.find("OO") != -1:
            flag = True
            txt = txt.replace("OO", "++")
    out += txt + "\n"

print("YES" if flag else "NO")
if flag:
    print(out.strip())
