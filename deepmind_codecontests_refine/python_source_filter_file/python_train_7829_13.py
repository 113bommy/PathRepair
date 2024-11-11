
e = str(input()) + str(input()) + str(input())
rptas = 'YES'
for i in range(4):
    if e[i] != e[8-i]:
        rpta = 'NO'
        break;
print(rptas)