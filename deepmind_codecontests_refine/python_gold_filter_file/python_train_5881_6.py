n= int(input())
lst1 = list(input())
lst2 = list(input())
arr = [0,1,2,3,4,5,6,7,8,9]
count =0
for i in range(n):
    start = int(lst1[i])
    finish = int(lst2[i])
    diff= start - finish
    if abs(diff) < (10 - abs(diff)):
        count += abs(diff)
    else:
        count += (10-abs(diff))
print(count)