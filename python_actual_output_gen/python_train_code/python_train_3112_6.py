n  = input()
a = 0
b = 0
for i in n:
    if i == "4":
        a = a+1
    elif i == "7":
        b = b+1
if a == 0 and b == 0:
    print("-1")
else:
    if a>b:
        print(4)
    else:
        print(7)