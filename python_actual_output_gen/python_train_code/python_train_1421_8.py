x = input().split();
a = [int(i) for i in x]
m = max(3*a[0]/10,a[0]-(a[0]*a[1])/250)
v = max(3*a[2]/10,a[2]-(a[2]*a[3])/250)
if (m==v):
    print("Tie")
elif (m>v):
    print("Misha")
else:
    print("Vasya")