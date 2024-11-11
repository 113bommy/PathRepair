n = int(input())
lst = list(map(int, input().split()))
mini = 1000
le = len(lst)
for i in range(le):
    if i != le-1:
        if mini > abs(lst[i]-lst[i+1]):
            mini = abs(lst[i]-lst[i+1])
            x = i+1
            y = i+2
            if mini == 1:
                break
    else:
        if mini > abs(lst[i]-lst[0]):
            mini = abs(lst[i]-lst[0])
            x = i+1
            y = 1
print(x,y)

    
    
    


