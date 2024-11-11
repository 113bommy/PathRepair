n = int(input())
s = input()
s = "0" + s + "0"
if n >= 3:
    if "11" in s or "000" in s:
        print("NO")
    else:
        print("YES")
elif n == 2:
    if s == "11" or s == "00":
        print("NO")
    else:
        print("YES")
else:
    if s == "1":
        print("YES")
    else:
        print("NO")