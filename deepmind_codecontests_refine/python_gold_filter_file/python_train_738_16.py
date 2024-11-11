n = int(input())

for d in range(2, 1+int(n**.5)):
    if not n%d:
        print((n-d+2)//2)
        break
else:
    print(1)