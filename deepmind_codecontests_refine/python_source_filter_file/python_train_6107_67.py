a = input()
sum = 0
check = True
value = a[0]
for i in range(len(a)):
    if value == a[i]:
        sum += 1
        if sum > 6:
            print("YES")
            check = False
            break
    else:
        value = a[i]
        sum = 0
if check:
    print("NO")