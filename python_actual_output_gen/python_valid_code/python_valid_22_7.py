input()
a = list(map(int, input().split()))
chest = biceps = back = 0
for i in range(0, len(a)):
    if i % 3 == 2:
        back += a[i]
    if i % 3 == 1:
        biceps += a[i]
    else:
        chest += a[i]
if back > biceps and back > chest:
    print('back')
    exit()
print('chest' if chest > back and chest > biceps else 'biceps')
