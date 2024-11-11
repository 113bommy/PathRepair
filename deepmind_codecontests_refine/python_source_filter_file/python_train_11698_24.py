n = int(input())
a = [0, 0]
b = [0, 0]


for i in range(n):
     x = list(map(int,input().split()))
     if x[0] == 1:
          a[0], a[1] = a[0] + x[1], a[1] + x[2]
     else:
          b[0], b[1] = b[0] + x[1], b[1] + x[2]

          
print('LIVE' if a[0] > a[1] else 'DEAD')
print('LIVE' if b[0] > b[1] else 'DEAD')