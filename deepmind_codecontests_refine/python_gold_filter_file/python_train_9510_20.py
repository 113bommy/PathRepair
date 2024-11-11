n = int(input())
array = list(map(int, input().split()))
if array.count(min(array)) > 1:
    print("Still Rozdil")
else:
    print(array.index(min(array)) + 1)