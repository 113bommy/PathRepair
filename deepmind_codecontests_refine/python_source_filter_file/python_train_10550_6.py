hash_set = set()
for i in range(10**5):
    hash_set.add(i*(i+1)//2)
n = int(input())

if n==1:
    print('NO')
    exit()

i = 0
while True:
    temp = (i * (i+1) // 2 )
    if temp > n:
        print('NO')
        break
    elif (n - temp) in hash_set:
        print('YES')
        break
    i += 1