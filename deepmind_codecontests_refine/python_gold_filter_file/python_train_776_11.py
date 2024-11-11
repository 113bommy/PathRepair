s=input()
m=int(max(s))
print(m)
for i in range(m):print(int(''.join('1' if int(c)>i else '0' for c in s)))