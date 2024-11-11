h, w = map(int,input().split())
a = [list(input()) for i in range(h)]
sum = 0
for b in a:
    sum+=b.count('#')

if sum == h+w-1:
    print('Possible')
else:
    print('Impossible')