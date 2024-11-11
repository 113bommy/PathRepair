n, x = map(int, input().split())

if x == 1:
    print("No")
elif x == 2*n-1:
    print("No")
else:
    print("Yes")
    result = [i for i in range(1, 2*n)]
    result = result+result
    p = n-x
    for i in result[2*n-1-p:2*n-1-p+2*n-1]:
        print(i)