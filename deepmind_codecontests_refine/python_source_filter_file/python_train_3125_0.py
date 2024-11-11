cnt = 0
n = int(input())
lst = list(map(int, input().split()))
for i in range(n):
    for j in range(n-1,i,-1):
        if lst[j] < lst[j-1]:
            lst[j-1:j+1] = lst[j], lst[j-1]
            cnt += 1
print(lst)
print(cnt)