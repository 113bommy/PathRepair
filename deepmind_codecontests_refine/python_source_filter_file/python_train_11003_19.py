nominals = (int(100),int(50), int(20), int(10), int(5), int(1))
vklad = int(input())
arve = int(0)
for i in nominals: 
    if(len(str(i)) <= len(str(vklad)) and vklad // i > 0):
        arve += vklad // i
        vklad -= (vklad // i) * i
print(arve)