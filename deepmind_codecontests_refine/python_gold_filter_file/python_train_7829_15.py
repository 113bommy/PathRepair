
e = str(input()) + str(input()) + str(input())
rpta = 'YES'
for i in range(4):
    if e[i] != e[8-i]:
        rpta = 'NO'
        break;
print(rpta)