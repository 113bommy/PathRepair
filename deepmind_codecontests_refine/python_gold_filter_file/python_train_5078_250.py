A,B=input().split()
print(int(A)*int(B[:1]+B[-2:])//100)