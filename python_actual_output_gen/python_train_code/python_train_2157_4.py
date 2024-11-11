def countbrackets(string):
    if string.replace("(", "").replace(")", ""): return None
    string = [x == '(' for x in string]
    bopen, extraclose = 0, 0
    for x in string:
        if x: bopen += 1
        else: 
            if bopen == 0: extraclose += 1
            else: bopen -= 1


    return bopen, extraclose

#input()
bstring = input()
ans = countbrackets(bstring) 
if ans == (1,1) or ans == (0,0):
        print("Yes")
else:
        print("No")