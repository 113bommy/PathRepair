n = int(input())
resList = [0]*(2*n-1)
resList[0] = 1
for i in range(2*n-1):
    for i in range(2*n-2):
        resList[i+1] += resList[i]
print(max(resList))