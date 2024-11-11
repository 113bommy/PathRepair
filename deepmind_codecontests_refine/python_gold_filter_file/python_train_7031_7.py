a = [int(i) for i in input().split()]
if min(a[:len(a)-2]) < a[4]:
    print(0)
elif min(a[:len(a)-2]) > a[5]:
    print(a[5] - a[4] + 1)
else:
    print(min(a[:len(a)-2])-a[4])
