n = int(input())
l = list(map(int, input().split()))
c = 0
while all(i % 2 == 0 for i in l):
    a = [i/2 for i in l]
    c += 1
print(c)