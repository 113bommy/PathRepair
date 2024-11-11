n = int(input())
li = []
for i in range(n):
    li.append(int(input()))
sum = li[0] + 1
for i in range(n-1):
    if li[i] > li[i+1]:
        sum += min(li[i], li[i+1]) + 2
    else:
        diff = li[i+1] - li[i]
        sum += diff+2
    #print(sum)
print(sum)
