n, a, b = map(int, input().split())
cnt = 1

a += a % 2
b += b % 2
while a != b:
    cnt += 1
    a /= 2
    b /= 2
    a += a % 2
    b += b % 2
if 2 ** cnt == n:
    print('final!')
else:
    print(cnt)
    


    