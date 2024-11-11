name = input()
chars = []
for i in name:
    if(i not in chars):
        chars.append(i)

count = 0
for i in chars:
    count += 1

if(count%2 == 0):
    print("CHAT WITH HER")
else:
    print("IGNORE HIM")