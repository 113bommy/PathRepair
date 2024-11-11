nums, lens = map(int, input().split(" "))

k = input().split(" ")
k = [int(k[i]) for i in range(nums)]


sums = 0
sumx = 0
for i in range(nums):
    if k[i]>5:
        sums += 2
    elif k[i] <= 5:
        sumx += 1
counts = sums + sumx
print(counts)