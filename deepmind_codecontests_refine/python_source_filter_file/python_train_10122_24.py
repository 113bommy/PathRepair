t = int(input())
a=[]
b=[]
for i in range(t):
    xx = input().split()
    a.append(int(xx[0]))
    b.append(int(xx[1]))

for i in range (t):
    dif = a[i]-b[i]
    if dif == 0 :
        print(0)
    if dif > 0 :
        if dif%2==1:
            print(2)
        else:
            print(1)
    else:
        if dif%2==1:
            print(2)
        else:
            print(1)
