n = int(input())
result = 'NO'
for i in range(n):
    m = input().split(" ")
    if int(m[1]) > 2400 and int(m[2]) > int(m[1]):
        result = 'YES'
print(result)