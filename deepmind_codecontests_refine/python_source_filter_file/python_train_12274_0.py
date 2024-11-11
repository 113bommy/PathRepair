def time():
    A = list(map(int,input().split()))
    shussha = A[:3]
    taisha = A[3:]
    sec = ((taisha[2] + 60) - shussha[2] ) % 60
    kurisagari_min = int(taisha[2] - shussha[2] < 0)
    min = ((taisha[1] - kurisagari_min + 60) - shussha[1])  % 60
    kurisagari_hour = int(taisha[1] - kurisagari_min - shussha[1] < 0)
    hour =  taisha[0] - kurisagari_hour - shussha[0]
    return (str(hour)+" "+str(min)+" "+str(sec))
A = time()
B = time()
C = time()
print(A)
print(B)
print(C,end="")