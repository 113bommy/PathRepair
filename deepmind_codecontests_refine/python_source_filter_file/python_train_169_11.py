n = int(input())
s = input()
dic = {}
for i in range(0, n - 1):
    str = s[i:i + 2]
    if str in dic:
        dic[str] += 1
    else:
        dic[str] = 0
max, mtime = '', 0
for each in dic:
    if dic[each] > mtime:
        max, mtime = each, dic[each]
print(max)
