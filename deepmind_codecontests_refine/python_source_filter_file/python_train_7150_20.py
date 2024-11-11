s = input()
flag = False
for i in range(1, len(s) - 3):
    if s[i:i+3] in ("ABC", "BAC", "CAB", "ACB", "CBA"):
        flag = True
        break
if flag:
    print("Yes")
else:
    print("No")
