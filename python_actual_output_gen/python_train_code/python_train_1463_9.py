n = int(input())
m = int(input())

usbs = []
for i in range(n):
    usbs += [int(input())]
    
usbs.sort(reverse=True)    
curSum = 0
for i in range(len(usbs)):
    curSum += usbs[i]
    if curSum >= n:
        print(i + 1)
        break