n = int(input())
String = input()

rejectedSub = "xxx"
removeCount = 0
for i in range(n):
    if rejectedSub in String[i:]:
        removeCount += 1
print(removeCount)
