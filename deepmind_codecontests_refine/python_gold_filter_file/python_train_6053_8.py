a = []
for i in range(4):
    a.append(int(input()))
if((a[0] == a[-1]) and (a[0] > 0 or a[2] == 0)):
    print(1)
else:
    print(0)