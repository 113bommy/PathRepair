c = input()
sum = 1
check = True
value = c[0]
for i in range(1,len(c)):
    if value == c[i]:
        sum += 1
        if sum > 6:
            print("YES")
            check = False
            break
    else:
        value = c[i]
        sum = 1
if check:
    print("NO")