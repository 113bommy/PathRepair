n, k = map(int, input().split())
lst = input().split()
lst = [int(x)>=int(lst[k]) & int(x)>0 for x in lst]
print(sum(lst))