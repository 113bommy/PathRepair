n , k = map(int, input().split(' '))
slogan = input()
def begin():
    print('PRINT ' + slogan[0])
    for i in range(1, len(slogan)):
        print('RIGHT')
        print('PRINT ' + slogan[i])
def end():
    print('PRINT ' + slogan[-1])
    for i in range(2, len(slogan)+1):
        print('LEFT')
        print('PRINT ' + slogan[-i])
mid = n //2
if k == 1:
    begin()
elif k == n:
    end()
elif k > mid:
    diff = n-k
    for i in range(diff):
        print('RIGHT')
    end()
elif k < mid:
    diff = k -1
    for i in range(diff):
        print('LEFT')
    begin()
elif mid == k:
    for i in range(mid -1):
        print('LEFT')
    begin()