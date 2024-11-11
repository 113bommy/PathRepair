n = int(input())

if n%2 == 0 :
    print('NO')
else:
    print('YES')
    l_1 = [1]
    l_2 = [2]
    for i in range(1,n):
        l_1.append(l_1[-1]+ (i%2)*3 + abs((i%2-1))*1)
        l_2.append(l_2[-1]+(i%2)*1 + abs((i%2-1))*3)
    final_l = l_1 + l_2
    for x in final_l:
        print(x,end=' ')
