n,m=list(map(int, input().split(" ")))
current = 0
count = 0
true = False
toPrint = "OK"
for line in range(m):
    a,b = list(map(int, input().split(" ")))
    if a == current+1: current=b
    elif a > current+1: 
        current +=1
        true = True
        break;
    else:
        count=2
        for line2 in range(line+1, m):
            a,b =list(map(int, input().split(" ")))
            if a > current: break;
            elif a == current: count+=1
            else: current,count = a,2
        true = True
        break;
if true: print(current, count)
elif current == n: print("OK")
else: print(current+1, 0)