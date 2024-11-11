n = int(input())
first = []
second = []
sum = 0
for _ in range(n):
    a = int(input())
    if a > 0:
        first.append(a)
    else:
        second.append(-a)
    sum+=a
if (sum>0):
    print("first")
    exit()
if (sum<0):
    print("second")
    exit()
if first > second:
    print("first")
    exit()
if second > first:
    print("second")
    exit()
if a > 0:
    print("first")
else:
    print("second")