#from random import randint

#a = list(map(int, input().split()))
# a, b, c, d = map(int, input().split())
a = int(input())
for i in range(a, 1000000000):
    x = 0
    for j in range(len(str(i))):
        x += int(str(i)[j])
    if x % 4 == 0:
        print(i)
        exit(0)
