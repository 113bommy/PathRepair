s = input()

checked = [[False for x in range(4)] for y in range(4)]

def calculate_zeros(ch):
    counter = 0
    for i in range(4):
        for j in range(4):
            if(ch[i][j]==False):
                counter +=1
    return counter

def produce_trnsformation(ch):

    new_ch =[[False for x in range(4)] for y in range(4)]

    for i in range(4):
        for j in range(4):
            new_ch[i][j] = ch[i][j]

    for i in range(4):
        c_stroki = 0
        for j in range(4):
            if(ch[i][j]==True):
                c_stroki +=1
        if(c_stroki==4):
            new_ch[i][0] = False
            new_ch[i][1] = False
            new_ch[i][2] = False
            new_ch[i][3] = False

    for j in range(4):
        c_stolb = 0
        for i in range(4):
            if(ch[i][j]==True):
                c_stolb +=1
        if(c_stolb==4):
            new_ch[0][j] = False
            new_ch[1][j] = False
            new_ch[2][j] = False
            new_ch[3][j] = False

    new_val = calculate_zeros(new_ch)

    return (new_val,new_ch)


def ch_to_tmp(ch):

    tmp = [[False for x in range(4)] for y in range(4)]

    for i in range(4):
        for j in range(4):
            tmp[i][j] = ch[i][j]

    return tmp

tmp =  ch_to_tmp(checked)


for i in range(len(s)):
    if(int(s[i])==0):
        maximum = -1
        best_matrix = checked
        best_i = 0
        best_j = 0

        for j in range(4):
            for i in range(3):
                if(checked[i][j]== False and checked[i+1][j]==False):
                    tmp[i][j] = True
                    tmp[i+1][j] = True
                    tmp_elem = produce_trnsformation(tmp)
                    b = tmp_elem[0]

                    if(b>maximum):
                        maximum = b
                        best_matrix = tmp_elem[1]
                        best_i = i
                        best_j = j

                    tmp[i][j] = False
                    tmp[i+1][j] = False

        checked = best_matrix
        tmp = ch_to_tmp(checked)
        print(str(best_i)+ ' ' + str(best_j))


    else:
        maximum = -1
        best_matrix = checked
        for i in range(4):
            for j in range(3):
                if (checked[i][j] == False and checked[i][j+1] == False):
                    tmp[i][j] = True
                    tmp[i][j+1] = True
                    tmp_elem = produce_trnsformation(tmp)
                    b = tmp_elem[0]

                    if (b> maximum):
                        maximum = b
                        best_matrix = tmp_elem[1]
                        best_i = i
                        best_j = j

                    tmp[i][j] = False
                    tmp[i][j+1] = False

        checked = best_matrix
        tmp = ch_to_tmp(checked)
        print(str(best_i)+ ' ' + str(best_j))








