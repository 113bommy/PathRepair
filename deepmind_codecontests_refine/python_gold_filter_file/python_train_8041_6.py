k = int(input())
for _ in range(k):
    n = int(input())
    val = list(map(int, input().split()))
    ev,od = 0,0
    for i in range(n):
        if (i%2==0 and val[i]%2!=0):
            ev += 1 
        if (i%2!=0 and val[i]%2==0):
            od += 1
    if not (abs(ev-od)):
        print(ev)
    else:
        print('-1')