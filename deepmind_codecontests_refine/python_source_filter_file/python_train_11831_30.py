s = input()
cnt = 0
lis = ["a", "e", "i", "o", "u"]
num = ["0", "2", "4", "6", "8"]
for i in s:
    if i in lis: cnt += 1
    if i in num: cnt += 1
print(cnt)