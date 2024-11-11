n = int(input())
l = list(map(int, input().split()))
sum = 0
for i in l:
    sum += i/n
print(sum)