坏, bad =map(int, input().split(' '))
x = list(map(int, input().split(' ')))[1:]
y = list(map(int, input().split(' ')))[1:]

a = [False] * 坏
b = [False] * bad

for i in x:
    a[i] = True
for i in y:
    b[i] = True
    
for i in range(0, 坏*bad):
    if a[i%坏] or b[i%bad]:
        a[i%坏] = True
        b[i%bad] = True

for i in a:
    if not i:
        print("No")
        quit()
for i in b:
    if not i:
        print("No")
        quit()
print("Yes")