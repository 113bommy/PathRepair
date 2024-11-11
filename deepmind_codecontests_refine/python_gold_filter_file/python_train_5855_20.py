x = int(input())
for i in range(2, x):
   if x % i == 0:
        print(i, x // i, sep='')
        break