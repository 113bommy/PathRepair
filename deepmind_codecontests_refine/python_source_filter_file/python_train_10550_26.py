import math
funk = []
n = int(input())
for i in range(2*int(math.sqrt(n))+1):
    funk.append(i*(i+1)// 2)


i = 0
j = len(funk) - 1

while j >= i:
    if funk[i] + funk[j] > n:
        j -= 1
    elif funk[i] + funk[j] < n:
        i += 1
    else:
        print("YES")
        exit()

print("NO")