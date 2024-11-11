v = ['a', 'e', 'i', 'o', 'u']
s = input()
t = 0
for c in s:
    if c in v:
        t += 1
    elif 48<=ord(c)<58 and ord(c)%2==0:
        t += 1
print(t)
