from math import pi

input()
X = sorted(list(map(int, input().split())))
Red = X[::2]
Blue = X[1::2]
for i in range(len(Red)):
    Red[i] = (Red[i] ** 2) * pi
for i in range(len(Blue)):
    Blue[i] = (Blue[i] ** 2) * pi
print(sum(Red) - sum(Blue))

# UB_CodeForces
# Advice: Falling down is an accident, staying down is a choice
# Location: Here in Bojnurd
# Caption: So Close man!! Take it easy!!!!
# CodeNumber: 631

