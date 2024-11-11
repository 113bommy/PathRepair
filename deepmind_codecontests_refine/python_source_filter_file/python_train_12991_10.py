
N = int(input())


if N == 3:

    ans = [".aa","b..","b.."]

    for i in ans:
        print (i)

elif N >= 4:

    four = ["abcc","abdd","eefg","eefg"]
    five = ["ahhgg","ai..f","bi..f","b.jje","ccdde"]
    six = ["add.ff","a.ce..","bbce..",".ffadd","e..a.c","e..bbc"]
    seven = [".iijjkk","fadd...","fa.c...","gbbc...","g...add","h...a.c","h...bbc"]

    ans = [ ["."] * N for i in range(N) ]

    now = 0
    while N-now > 7:

        for i in range(4):
            for j in range(4):

                ans[i+now][j+now] = four[i][j]

        now += 4

    if N - now == 4:
        for i in range(4):
            for j in range(4):

                ans[i+now][j+now] = four[i][j]

    elif N - now == 5:
        for i in range(5):
            for j in range(5):

                ans[i+now][j+now] = five[i][j]

    elif N - now == 6:
        for i in range(6):
            for j in range(6):

                ans[i+now][j+now] = six[i][j]

    else:
        for i in range(7):
            for j in range(7):

                ans[i+now][j+now] = seven[i][j]

    for i in range(N):
        print ("".join(ans[i]))

else:
    print (-1)
