n = int(input())

if n < 6:
    print(-1)
else:
    print("1 2\n1 3\n1 4")
    for i in range(5, n+1):
        print('2 ' + str(i))
for i in range(1, n):
    print(str(i) + str(i+1))
