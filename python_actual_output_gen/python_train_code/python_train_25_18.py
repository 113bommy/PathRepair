n = int(input())
temp = [int(x) for x in input().split()]
a = 0
b = 0
for i in range(len(temp)-1):
    if temp[i] <= 500000 and temp[i+1] >= 500001:
        a = temp[i]
        b = temp[i+1]
if a == 0:
    print(min(temp[-1]-1, 1000000-temp[-1]))
else:
    print(max(a-1, 1000000-b))
