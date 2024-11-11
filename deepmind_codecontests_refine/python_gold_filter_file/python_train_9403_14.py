n, k = map(int, input().split())
lst = input().split()
lst = [(int(x)>=int(lst[k-1])) & (int(x)>0) for x in lst]
print(sum(lst))