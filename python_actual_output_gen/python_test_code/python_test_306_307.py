s = str(input())
m = n = str()
k = i = 0
for i in range(len(s)):
    if s[i] != " ":
        m += s[i]
    else:
        k = i + 1
        break;
while k != len(s):
    n += s[k]
    k+=1
m = int(m)
n = int(m)
a = int(m * n * 0.5)
print(a)