n = int(input())
s = input()
c = (n * (n+1)) / 2
i = 1
for d in s:
    if not((d=='0') or (d == '2') or (d == '4') or (d == '6') or (d == '8')):
        c -= i
    i += 1

print(c)
