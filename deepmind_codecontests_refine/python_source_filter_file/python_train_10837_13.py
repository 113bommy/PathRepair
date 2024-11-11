MAX_COLS = 20

s = input()

length = len(s)
separator = 0
if length <= MAX_COLS:
    print(1, length)
    print(s)
else:
    rows = (length + MAX_COLS - 1) // MAX_COLS
    cols = (length + rows - 1) // rows
    print(rows, cols)
    diff = rows * cols - length
    flag = False
    for i in range(rows):
        if i < (rows - diff):
            print(s[cols * i : cols * (i + 1)])
        else:
            if flag == False:
                 print(s[cols * i : cols + cols - 1], '*', sep='')
                 separator = cols + cols - 1
                 flag = True
            else:  
                print(s[separator : separator + cols - 1], '*', sep='')    
                separator  = separator + cols -1
 