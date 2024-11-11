count1 = 0
count2 = 0
nm = input().split()


n = int(nm[0])
m = int(nm[1])

if n == 1 and m == 1:
    print(1)
elif m-1 > (n-m):
    print(m-1)
else:
    print(m + 1)