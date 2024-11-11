s = ["Danil", "Olya", "Slava", "Ann", "Nikita"]
num = 0
ss = input()
for i in range(5):
    if (0 <= ss.find(s[i]) < len(ss)):
        num += 1
        ss = ss.replace(s[i], "1", 1)
for i in range(5):
    if (0 <= ss.find(s[i]) < len(ss)):
        num += 1
if (num == 1):
    print("YES")
else:
    print("NO")
