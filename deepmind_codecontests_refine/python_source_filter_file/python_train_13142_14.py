t = int(input())
for _ in range(t):
    a,k = map(int,input().split())
    cur = 1
    num = a
    while True:
        if cur == k:
            break
        cur += 1
        newnum = num+min(list(map(int,list(str(num)))))+max(list(map(int,list(str(num)))))
        if newnum==num:
            break
        num = newnum
    print(num)
        