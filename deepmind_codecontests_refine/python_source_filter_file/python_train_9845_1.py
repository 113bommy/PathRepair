a = int(input())
b = str(input())
cp = 0
cc = 0
for i in range(len(b)):
    if b[i] == 'A':
        cp += 1
    else :
        cc+= 1
if cp> cc:
    print("Anton")
elif cp<cc:
    print ("Danik")
else:
    print("friendship")