s = input()
t = input()

count = 1
for i in range(len(t)):
    if t[i] == s[count]:
        count += 1

print(count)