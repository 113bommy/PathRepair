n = int(input())
array = list(map(int, input().split()))
if array.count(min(array)) > 2:
    print("Still")
else:
    print(array.index(min(array)) + 1)