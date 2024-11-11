
a = [int(s) for s in input().split()]
x = [int(s) for  s in input().split()]
if ((a[2]-a[0]) % x[0] == 0) and ((a[3] - a[1]) % x[1] == 0) and (((a[2]-a[0]) == 0 or (a[3] - a[1]) ==0) and (abs((abs(((a[2]-a[0]) // x[0]) - abs((a[3] - a[1]) // x[1]))) % 2 ==0))):
    print("Yes")
elif ((a[2]-a[0]) % x[0] == 0) and ((a[3] - a[1]) % x[1] == 0) and ((a[2]-a[0]) // x[0] == (a[3] - a[1]) // x[1]):
    print("Yes")
elif ((a[2]-a[0]) % x[0] == 0) and ((a[3] - a[1]) % x[1] == 0) and (abs((abs(((a[2]-a[0]) // x[0]) - abs((a[3] - a[1]) // x[1]))) % 2 ==0)):
    print("Yes")
else:
    print("No")
