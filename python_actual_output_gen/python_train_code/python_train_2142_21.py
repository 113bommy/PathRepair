#909A
p,s = input().split(" ")
l = p[0]
for i in p[1:]:
    if i > s[0]:
        break
    else:
        l += i
print(l + s[0])
