n = int(input())
lst = list(map(int, input().split()))
lst.sort()
#print(lst)
rs = 0
sum = 0
for i in lst:
    if sum <= i:
        rs += 1
        sum += i
print(rs)