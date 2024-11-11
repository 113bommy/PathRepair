n, m = list(map(int, input().split(' ')))
for i in range(0,n, 1):
   # print(i)
    if i % 2 > 0:
        if i % 3 == 0:
            sstrin = '#' +  '.'*(m - 1)
            print(sstrin)
        else :
            sstrin = '.' *(m-1) + '#'
            print(sstrin)
    else:
        sstrin = '#' * (m)
        print(sstrin)