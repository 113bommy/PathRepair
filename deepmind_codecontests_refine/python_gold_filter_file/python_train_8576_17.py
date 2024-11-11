n = int(input())
N = -n
a = int((N-N%10)/10)
b = int((N-N%100)/10+N%10)
c = max(-a,-b,n)
print(c)
