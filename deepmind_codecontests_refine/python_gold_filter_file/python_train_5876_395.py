s = input()
t = input()
if s[0::] == t[::-1]:
    print("YES")
else:
    print("NO")