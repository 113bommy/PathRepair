s = input()
t = input()
if t == s[len(s)::-1]:
    print("YES")
else:
    print("NO")