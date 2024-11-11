x = int(input())
y = list(str(x))
result = 0
for i in range(x+1,9013):
    count = 0
    lst = list(str(i))

    for j in range(4):
        for k in range(j+1,4) :
            if lst[j] == lst[k]:
                count = 1
    if count == 0:
        result = ''.join(lst)
        break
                
print(result)