N = input()
l = len(str(N))-1
print(l*9 + (N//(10**l)-1))