A = list(str(input()).split(' '))
print(A)
w = int(A[0])
h = int(A[1])
k = int(A[2])
a = 0
for i in range(k):
    a = a + (h*w - (h-2)*(w-2))
    h = h-4
    w = w-4
    
print(a)
