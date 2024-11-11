n = int(input())
s = "{:06b}".format(n)
#print(s)
res = s[0] + s[5] + s[3] + s[1] + s[4] + s[2]
#print(res)
print(int(res, 2))