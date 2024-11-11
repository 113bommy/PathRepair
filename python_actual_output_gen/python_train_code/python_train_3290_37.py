n = input()
n = int(n)
a = []


for i in range(0,n):
    t1,t2,t3 = input().split()
    a.append(str(t1))
    a.append(int(t2))
    a.append(int(t3))

y = 0
for i in range(0,len(a),3):
    if a[i + 1] > 2400:
        if a[i + 1] < a[i + 2]:
            y = 1
            break
        else:
            y = 0

if y == 1:
    print ('YES')
else:
    print ('N0')
