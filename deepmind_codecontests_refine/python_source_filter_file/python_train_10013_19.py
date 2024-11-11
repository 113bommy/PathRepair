b = int(input())
g = int(input())
n = int(input())


count = 1

for i in range(n):
    gt = n - i
    if (gt > g or i > b):
        continue
    count+=1;

print(count)