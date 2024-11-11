t = int(input())
 
for i in range(t):
    n = int(input())
    t = (n-1) // 4
    for j in range(n-t-1):
        print(9, end='')
    print(8, end='')
    for j in range(t):
        print(8, end='')
    print()