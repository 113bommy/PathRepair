t = int(input())
arr = []
while (t>0) and (t< 10**4):
    n = int(input())
    if n in range (1,(2*(10**9))+1):
        arr.append(n)
    t -= 1

l = len(arr)
for i in range (0,l):
    x = arr[i]//2
    a = arr[i] - x
    if (a>0) and (x>0) and (a>x):
        print(x)
    elif a == x:
        x -= 1
        print(x)
    else:
        print(0)
