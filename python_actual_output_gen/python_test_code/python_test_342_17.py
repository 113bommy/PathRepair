n = int(input())
h = 0
while n >= h*(h+1)/2:
    h +=1
    n -= h*(h+1)/2
print(h)
