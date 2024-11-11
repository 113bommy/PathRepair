n = int(input())
if(n > 2):
    lst = list(map(int, input().split()))
    lst.sort()
    res = max(lst) - min(lst)
    for i in range(2):
        res = int(min(res,lst[n-2],lst[0]))
    print(res)   
if(n == 2):
    lst = list(map(int, input().split()))
    print('0')