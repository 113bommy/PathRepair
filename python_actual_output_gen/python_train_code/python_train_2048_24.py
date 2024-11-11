n = int(input())
list1 = list(map(int, input().split()))
for i in range(len(list1)):
    if list1[i] % 2 == 0:
        list1[i] = list1[i] - 1
    
print(list1)
    