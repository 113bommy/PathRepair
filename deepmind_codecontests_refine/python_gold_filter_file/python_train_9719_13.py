w = list(map(int,input().split()))
A1 = w[0]
#ab
A2 = w[1]
#bc
A3 = w[2]
#ca
vol = (A1*A2*A3)**(0.5)
#abc

a = vol/A2
b = vol/A3
c = vol/A1
print(int(4*(a+b+c)))
