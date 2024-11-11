s = list(input())
flag = "YES"

for x in s:
    if s.count(x) % 2 != 0:
        flag = "NO"

print(flag)