def cf31B():
    #print("Hello World")
    from sys import stdin,stdout
    inp = list(stdin.readline().strip().split('@'))
    flag = True
    if len(inp)>=2:
        if len(inp[0])==0 or len(inp[-1])==0:
            flag = False
        if flag:
            for i in range(1,len(inp)-1):
                if len(inp[i]) < 2:
                    flag = False
                    break
    else:
        flag = False

    answer = ""
    if flag:
        for i , j in enumerate(inp):
            if i==0:
                answer+=j
            elif i==len(inp)-1:
                answer+='@'+j
            else:
                answer+='@'+j[:-1]+','+j[-1]
    else:
        answer = "No solution"

    stdout.write(answer+"\n")

    
if __name__=='__main__':
    cf31B()
