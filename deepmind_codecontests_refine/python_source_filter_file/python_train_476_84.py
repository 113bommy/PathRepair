import math
#q = int(input().strip())
count=0
a = [int(x) for x in input().strip().split(' ')]
s=a[0]
v1 = a[1]
v2 = a[2]
t1 = a[3]
t2 = a[4]
first = 2*t1 + s*v1
second = 2*t2 + s*v2
#print(first," ", second)
if first<second:
    print("Second")
elif second<first:
    print("First")
else:
    print("Friendship")