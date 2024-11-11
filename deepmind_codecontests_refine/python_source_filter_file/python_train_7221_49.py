list1 = list(map(int, input().split()))
list1.extend(list(map(int, input().split())))
list1.extend(list(map(int, input().split())))
list1.extend(list(map(int, input().split())))
list1.extend(list(map(int, input().split())))
x = list1.index(1)
a = min(x % 5, 4 - x % 5) + 1
b = min(x // 5, 5 - x // 5) + 1
print(6-a-b)
