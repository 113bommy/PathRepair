n = int(input())
for i in range(n):
    temp = input().split(' ')
    if int(temp[1]) > 2400 and int(temp[2]) > int(temp[1]):
        print("YES")
        exit(0)
print("NO")
exit(0)