if __name__ == "__main__":
    giventime = input()
    toadd = int(input())
    hr = int(giventime.split(':')[0]) if giventime.split(':')[0][0]!='0' else int(giventime.split(":")[0][1])
    minute = int(giventime.split(':')[1]) if giventime.split(':')[1][0]!='0' else int(giventime.split(":")[1][1])
    # now I have hr and minute thge initial ones
    totalminutes = minute + toadd
    if totalminutes <= 60:
        h = 0
        outputm = totalminutes
    else:
        h = totalminutes // 60
        outputm = totalminutes % 60
    totalhrs = hr + h
    if totalhrs<24:
        outputh = totalhrs
    else:
        while totalhrs>=24:
            totalhrs = totalhrs - 24
        outputh = totalhrs
    if len(str(outputh)) == 1:
        outputh = '0' + str(outputh)
    else:
        outputh = str(outputh)
    if len(str(outputm)) == 1:
        outputm = '0' + str(outputm)
    else:
        outputm = str(outputm)
    print(str(outputh)+':'+str(outputm))                                    