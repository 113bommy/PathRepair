input()
password = input()
shuffle = input()

rotations = 0
bigNo = 11
for i in range(len(password)):
    passInt = int(password[i])
    shuffleInt = int(shuffle[i])
    if passInt != shuffleInt:
        if abs(passInt - shuffleInt) > 5:
            bigNo =  passInt if passInt > shuffleInt else shuffleInt
            smallNo =  passInt if passInt < shuffleInt else shuffleInt
            cRotations = 10 - bigNo + smallNo
        else:
            cRotations = abs(passInt - shuffleInt)
    else:
        cRotations = 0
    rotations+=cRotations
print(rotations)