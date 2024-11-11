n = int(input())
b = [int(x) for x in input().split()]
count = abs(b[0])
for i in range(1, n):
    count += abs(b[i]-b[i-1])
print(count)
        
