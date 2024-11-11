n = int(input())
l = list(map(int, input().split()))
a = ""
flag = 1
if n % 2 == 0:
    print("No")
    exit()
else:
    for i in l:
        if i %2 == 0:
            a = a+ "0"
        else:
            a = a+"1"

if a[0]!="1" and a[-1]!="1":
    flag = 0
if flag==0:
    print("No")
else:
    print("Yes")