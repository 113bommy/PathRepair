n = int(input())
if n<10:
    q = n
else:
    if n<190:
        k = (n+10)//2
        if n%2==0:
            q = k//10
        else:
            q = k%10
    else:
        k = (n+110)//3
        if n%3==1:
            q = k//100
        elif n%3 ==2:
            q = (k%100)//10
        else:
            q = k%10
print(q)