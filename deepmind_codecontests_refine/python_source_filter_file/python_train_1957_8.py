n = int(input())-97
s = input()
ans = ''
for x in s:
    ans += chr((ord(x)+n)%26 + 97)
print(ans)