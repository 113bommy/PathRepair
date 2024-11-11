r, c = [int(x) for x in input().split()]
list_2 = []
index = 0
previous = -1
for i in range(r):
    list_2.append(list(input()))
for i in range(r):
    index = list_2[i][0]
    for j in range(c):
        if index != list_2[i][j] or list_2[i][j]==previous:
            print("NO")
            exit()
        previous = index


print("YES")




