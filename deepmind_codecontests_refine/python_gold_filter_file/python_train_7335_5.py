n = int(input())
fir = [0]*n
sec = [0]*n
i = 0
i1 = 0
summ =0
summ1 =0
ai = 0
en = 0
for num in range(n):
    ai = int(input())
    if ai >0:
        fir[i] = ai
        summ+=ai
        i+=1
    else:
        sec[i1] = -(ai)
        summ1 += -(ai)
        i1+=1
if summ1>summ:
    print("second")
elif summ>summ1:
    print("first")
elif summ==summ1:
    for num in range(n):
        if fir[num] > sec[num] :
            print("first")
            en = 1
            break
        elif fir[num] < sec[num]:
            print("second")
            en = 1
            break
    if en == 0:
        if ai >0:
            print("first")
        else:
            print("second")
