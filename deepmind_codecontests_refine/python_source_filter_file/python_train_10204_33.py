n = input()
lst = list(map(int,input().split())
for i in range(n):
    key = lst[i]
    j = i-1
    while j >= 0 and lst[j] > key:
        lst[j+1] = lst[j]
        j -= 1
    lst[j+1] = key
    print(' '.join(map(str,lst)))