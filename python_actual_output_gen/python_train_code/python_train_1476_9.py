inputs = input()

a = inputs

ans = 0
while len(a) > 1:
    if a[0] == a[-1]:
        a = a[1:-1]
    if a[0] == 'x' and a[-1] != 'x':
        ans += 1
        a += 'x'
    if a[0] != 'x' and a[-1] == 'x':
        ans += 1
        a = 'x' + a
    if a[0] != a[-1]:
        ans = -1
        break
        
print(ans)