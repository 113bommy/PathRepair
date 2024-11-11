s = input()
k = int(input()) - 1
i = 0
while i < k and s[i] == '1':
    i += 1
print(s[i])
