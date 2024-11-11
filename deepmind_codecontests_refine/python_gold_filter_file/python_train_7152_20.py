s = input()
flag = False
for i in range(0, len(s) - 2):
    if s[i:i+3] in ("ABC", "BAC", "BCA", "CAB", "ACB", "CBA"):
        flag = True
        break
if flag:
    print("Yes")
else:
    print("No")
