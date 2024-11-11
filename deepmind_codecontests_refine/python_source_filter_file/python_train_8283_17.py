a = int(input())
b = int(input())
c = int(input())
d = int(input())

print(1-(((a|b)&(c^d))|((b&c)^(a|d))))
