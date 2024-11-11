n = int(input())
numbers = list(map(int, input().split()))
nepnum = 0
for item in numbers:
    nepnum += item % 2
if(nepnum % 2 == 1):
    print("First")
else:
    print("Second")
