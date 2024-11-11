def searchstar(i,j):
    global vector
    global star
    global n
    flag = False
    for k in range(n):
        if star[i][0] + vector[j][0] == star[k][0] and star[i][1] + vector[j][1] == star[k][1]:
            flag = True
            break
    return flag

while True:
    m = int(input())
    if m==0: break

    vector = []

    x1,y1 = map(int, input().split())
    for i in range(m-1):
        x2,y2 = map(int, input().split())
        vector.append([x2-x1,y2-y1])

    star = []
    n = int(input())
    for i in range(n):
        a,b = map(int, input().split())
        star.append([a,b])

    for i in range(n):
        for j in range(m-1):
            if not searchstar(i, j):
                break
        else:
            print(star[i][0] - x1, star[i][1] - y1)
            break