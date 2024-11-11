L = 0
H = 0
while True:
    try:
        H,L = input('').split()
        L = float(L)
        H = float(H)
        if H < 1 or H > L or L > (10**6):
            raise ValueError
        break
    except ValueError:
        print("invalid Values")
x = float(((L**2)-(H**2))/(2*H))
print ("",end="") 
print ('%.13f'%x)