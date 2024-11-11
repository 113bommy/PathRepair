y, k, n = input().split()
check = False
y, k, n = [int(y), int(k), int(n)] 
if y > k:
    a = k-y%k
    for i in range(a, n, k):
        if i+y <= n:
            print(i, end = ' ')
            check = True
        else:
            break
elif y < k:
    a = k-y
    for i in range(a, n, k):
        if i+y <= n:
            check = True
            print(i, end = ' ')
        else:
            break
if check == False:
    print("-1")
