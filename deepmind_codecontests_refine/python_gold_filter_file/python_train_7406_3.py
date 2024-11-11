n = int(input()); lst = (input().replace(' ', '')).split('0')
lst[len(lst)-1] += lst[0]
lst.sort(reverse=True)
print(len(lst[0]))


