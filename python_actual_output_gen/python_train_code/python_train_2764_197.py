n = int(input())
l = list(map(int, input().split()))
sum = 0
for i in l:
    sum += i/2
print(sum)