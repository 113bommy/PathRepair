X=int(input())
Y=100
num=0
while Y<X:
    Y += Y//100
    num += 1
print(Y)
print(num)