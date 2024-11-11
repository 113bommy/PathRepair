##n = int(input())
##a = list(map(int, input().split()))
##print(" ".join(map(str, res)))

n = int(input())
a = list(map(int, input().split()))

while True:
    update = False
    for l in range(n-1):
        if a[l] > a[l+1]:
            a[l], a[l+1] = a[l+1], a[l]
            update = True
            print(l+1, l+2)
    if update == False:
        break
print(a)