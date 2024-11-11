s = input().strip()
s = set(s[1:len(s)-1].split(", "))
print(s)
if s=={""}:
    print(0)
else:
    print(len(s))