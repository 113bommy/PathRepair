t = [int(i) for i in input().split()]
m=max((3*t[0])/10,t[0]-((t[0]/150)*t[2]))
v=max((3*t[1])/10,t[1]-((t[1]/150)*t[3]))
if v==m:
    print("Tie")
elif v>m:
    print("Vasya")
else:
    print("Misha")
