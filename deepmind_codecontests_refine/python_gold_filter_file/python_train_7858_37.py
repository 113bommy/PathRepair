a = int(input())
b = list(map(int, input().split()))
c = 0
d = []
if (len(b) == 1):
    print(1)
else:
    for i in range(1, len(b)):
 
        if (b[i-1] <= b[i]):
            c+=1
            d.append(c)
        else :
            c=0
    if (len(d)==0):
        print(1)
    else:
        print(max(d)+1)
