a, b = input().split()
b = int(b)
list1 = list(input().split())
list1 = sorted(list1)
count = 0
for i in list1:
    i = int(i)
    if 5 - b > i:
        count+=1
print(int(count/3))

