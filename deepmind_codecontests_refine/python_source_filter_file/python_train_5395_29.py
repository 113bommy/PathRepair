N = int(input())
l = [105, 135, 165, 189, 195]
for i in range(5):
    if N < l[i]:
        print(i)
        exit(1)
print(5)
