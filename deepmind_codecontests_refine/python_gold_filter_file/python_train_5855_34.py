n = int(input())
for i in range(2,999):
    if n % i == 0:
        print(i, n//i, sep='')
        break
