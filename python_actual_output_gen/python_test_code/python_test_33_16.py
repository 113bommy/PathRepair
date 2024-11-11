x = 0
global q
b = int(input())
for q in range(0, 100000):
    x += 5*2**q
    if x>= b:
        break
prev = x - 5*2**q

serial = b - prev

z = serial/(2**q)
if z<=1:
    print("Sheldon")
elif z<=2:
    print("Leonard")
elif z<=3:
    print("Penny")
elif z<=4:
    print("Raj")
elif z<=5:
    print("Howard")

