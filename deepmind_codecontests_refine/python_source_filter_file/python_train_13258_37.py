a, b = map(int, input().split(' '))
dragons = [list(map(int, input().split(' '))) for dragon in range(b)]

key = False
while dragons != [] and key != True:
    okdrags = [dragon for dragon in dragons if dragon[0] <= a]
    if okdrags == []:
        key = True
    else:
        maximum = max(okdrags, key = lambda x: x[1])
        dragons.remove(maximum)
        a += maximum[1]

if dragons != []:
    print("NO")

else:
    print("YES")
