n = int(input())
s = input()
c1 = 0
c2 = 0
c = 0
for i in s:
    if i == '(':
        c1 += 1
    else:
        c2 += 1
        if c1 < c2:
            c += 1
print('('*c + s + ')'*(c+c1-c2))