x = int(input())
if x == 0:
    print(4)
    print(3, 3, 3, 3)
    1/0

x-= 1
phase = x//50
subphase = x%50
pstart = phase*50

left = 99+phase-(x-pstart)
right = 48+phase-(x-pstart)
ans = [left]*(1+subphase)+[right]*(49-subphase)
print(50)
print(*ans)