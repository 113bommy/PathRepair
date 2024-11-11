l = input().split(" ")

a = int(l[0])
b = int(l[1])
s = int(l[2])
diff = s - abs(a + b)

if diff >= 0 and diff % 2 == 0:
    print("Yes")
else:
    print("No")