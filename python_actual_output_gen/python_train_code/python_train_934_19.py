n = int(input())
s = input().split()
m = 0

for word in s:
    tm = 0
    for symbol in word:
        if symbol.isupper():
            tm += 1
    if tm > m:
        m = tm

print(tm)
