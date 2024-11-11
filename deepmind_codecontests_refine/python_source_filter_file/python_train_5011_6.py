input()
lamps = list(input())

res = 0
for i in range(len(lamps)-1):
    if lamps[i] == lamps[i+1]:
        if i == len(lamps)-2:
            if lamps[i] != "B":
                lamps[i+1] = "B"
            else:
                lamps[i+1] = "R"
        else:
            if lamps[i] == "B":
                if lamps[i+2] != "R":
                    lamps[i+1] = "R"
                else:
                    lamps[i+1] = "G"
            elif lamps[i] =="G":
                if lamps[i+2] != "R":
                    lamps[i+1] = "R"
                else:
                    lamps[i+1] = "R"
            else:
                if lamps[i+2] != "B":
                    lamps[i+1] = "B"
                else:
                    lamps[i+1] = "G"
        res+=1
print(res)
res = ""
for i in lamps:
    res+= str(i)
print(res)