n,x,y = list(map(int,input().split()))
list_input = list(map(int,input().split()))
if x > y:
    print(len(list_input))
else:
    c = 0
    for i in list_input:
        if c <= x:
            c += 1
    print((c + 1) // 2)
