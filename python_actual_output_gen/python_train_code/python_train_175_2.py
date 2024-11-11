spam = input()
spam = spam.split(' ')
n = int( spam[0])
k = int( spam[1])

spam = input()
spam = spam.split(' ')

count = 0
for i in range( n ):
    w = int( spam[ i ] )
    count = count + w//k
    w = w - w//k * k
    if w > 0:
        count = count + 1

ans = count // 2
if count == 2 * ans:
    print(count)
else:
    print( ans + 1)
