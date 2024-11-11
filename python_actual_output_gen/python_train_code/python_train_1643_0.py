s = input()
pole = input()
t = 0
count = 0
for i in range(len(pole)):
    if pole[i] == s[t]:
        t += 1
    if t == len(s):
        break
    count += 1
t -= 1
for i in range(len(pole) - 1, -1, -1):
    if pole[i] == s[t]:
        t -= 1
    if t == -1:
        count1 = i
        break
if count - count1 > 0:
    print(count1 - count)
else:
    print(0)