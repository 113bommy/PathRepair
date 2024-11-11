s = input()
t = input()
temp = list(s)
if t == "".join(s[::-1]):
    print("Yes")
else:
    print("NO")