def getHour(num, horas, minutos):

    dezHoras = int(horas[0])
    uniHoras = int(horas[1])

    dezMin = int(minutos[0])
    uniMin = int(minutos[1])

    if(num == 12):

        if(dezHoras*10 + uniHoras > 12 and uniHoras != 0):
            dezHoras = 0

        elif(dezHoras*10 + uniHoras > 12 and uniHoras == 0):
            dezHoras = 1

        elif(dezHoras*10 + uniHoras == 0):
            uniHoras = 1

        if(dezMin >= 6):
            dezMin = 0

        return "{}{}:{}{}".format(str(dezHoras), str(uniHoras), str(dezMin), str(uniMin))

    else:

        if(dezHoras*10 + uniHoras > 24):
            dezHoras = 0

        if(dezMin >= 6):
            dezMin = 0

        return "{}{}:{}{}".format(str(dezHoras), str(uniHoras), str(dezMin), str(uniMin))

num = int(input())
entrada = input().split(":")

horas = entrada[0]
minutos = entrada[1]

print(getHour(num, horas, minutos))