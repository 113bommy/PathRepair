n = int(input())
list_in = []
for i in range(n):
    a = [int(x) for x in input().split()]
    list_in.append(a)
k = int(input())

index = 0
while(k >= list_in[index][0] and index < n):
    index += 1

print(n-index)
