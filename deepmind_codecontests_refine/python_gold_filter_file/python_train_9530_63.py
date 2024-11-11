N = int(input())
flag = "NO"
for i in range(N):
    data = list(map(str, input().split(' ')))
    if int(data[1])>=2400 and int(data[1]) < int(data[2]):
        flag = "YES"
print(flag)




