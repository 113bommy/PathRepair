s=input()
U=0
D=0
L=0
R=0
for ch in s:
    if ch=="U":
        U+=1
    if ch=="D":
        D+=1
    if ch=="L":
        L+=1
    if ch=="R":
        R+=1
if (U+D+R+L)%2==1:
    print ("-1")
else:
    changeup=abs(U-D)/2
    changel=abs(U-D)/2
    print (int(changeup+changel))
