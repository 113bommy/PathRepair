m = int(input())
x = input()
n = int((-1 + ((1 + 8*m)**0.5))/2)
k = ''
for i in range(n):
    k += x[int((i**2+i)/2)]
print(k)