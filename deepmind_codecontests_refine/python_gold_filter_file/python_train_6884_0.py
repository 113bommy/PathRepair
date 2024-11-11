s = input()
a = s.find("[")
b = s.rfind("]")
if a > b or a == -1 or b == -1:
    print(-1)
else:
    c = s.find(":", a, b)
    d = s.rfind(":", a, b)
    if c >= d:
        print(-1)
    else:
        print(s.count("|", c, d) + 4)
