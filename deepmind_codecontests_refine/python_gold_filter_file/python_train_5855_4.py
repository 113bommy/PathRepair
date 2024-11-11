a = int(input())
for i in range(2,1000):
    if a % i == 0:
        print(str(i)+str(a//i))
        break
