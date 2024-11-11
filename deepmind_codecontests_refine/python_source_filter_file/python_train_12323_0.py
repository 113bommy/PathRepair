arr=[         list(  input()   )      for _ in range (8)      ]
cw=0
cb=0
flag = False
# WBWBWBWB
# WBWBWBWB
# BWBWBWBW
# WBWBWBWB
# WBWBWBWB
# WBWBWBWB
# WBWBWBWB
# # BWWWBWBW
for i in range(8):
    for j in range(8):
        if ((arr[i][j]) == "W") and j == 7:
            cw+=1
        elif ((arr[i][j]) == "B") and j == 7:
            cb+=1
        elif (((arr[i][j]) == "B") and (arr[i][j+1] == "B")) or (((arr[i][j]) == "W") and (arr[i][j+1] == "W")):
            cb-=1    
        elif ((arr[i][j]) == "W") and (arr[i][j+1] == "B") and j != 7:
            cw+=1
        elif ((arr[i][j]) == "B") and (arr[i][j+1] == "W") and j != 7:
            cb+=1
    if cw == cb :
        # print(cw,cb)
        cw=cb=0
        flag = True
        continue
    else:
        flag= False
        print('NO')
        break
if  (flag == True):
    print("YES")
