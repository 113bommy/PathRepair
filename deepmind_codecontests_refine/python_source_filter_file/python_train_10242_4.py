l = [["1" for x in range(3)] for p in range(3)]
i = [[x for x in map(int, input().split())] for t in range(3)]
for indx1,num in enumerate(i):
    for indx2,num1 in enumerate(num):
        if num1 % 2 != 0 and num1 != 0:
            if l[indx1][indx2] == "1":
                l[indx1][indx2] = "O"
            else:
                l[indx1][indx2] = "1"
            if indx2 + 1 in [0,1,2]:
                if l[indx1][indx2 + 1] == "1":
                    l[indx1][indx2 + 1] = "O"
                else:
                    l[indx1][indx2 + 1] = "1"
            if indx2 - 1 in [0,1,2]:
                if l[indx1][indx2 - 1] == "1":
                    l[indx1][indx2 - 1] = "O"
                else:
                    l[indx1][indx2 - 1] = "1"
            if indx1 + 1 in [0,1,2]:
                if l[indx1 + 1][indx2] == "1":
                    l[indx1 + 1][indx2] = "O"
                else:
                    l[indx1 + 1][indx2] = "1"
            if indx1 - 1 in [0,1,2]:
                if l[indx1 - 1][indx2] == "1":
                    l[indx1 - 1][indx2] = "O"
                else:
                    l[indx1 - 1][indx2] = "1"
for t in l:
    for tt in t:
        print(tt,end='')
    print('')