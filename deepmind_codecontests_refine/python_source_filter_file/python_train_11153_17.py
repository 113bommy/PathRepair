n = int(input())
a = input()
if n == 1:
    print(0)
    print(a)
    exit()
    
posl = [list('RGB'), list('RBG'), list('BRG'), list('BGR'), list('GBR'), list('GRB')]
m = 0
se = 0
kak = 0
for j in range(6):
    se = 0
    for i in range(n):
        if a[i] == posl[j][i % 3]:
            se += 1
    if se > m:
        m = se
        kak = j

print(n - se)
for i in range(n):
    print(posl[kak][i % 3], end='')
print()

