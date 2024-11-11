s=input()

BW=s[::2]
WB=s[1::2]

x=BW.count("0") + WB.count("1")
y=BW.count("0") + WB.count("1")

print(min(x,y))