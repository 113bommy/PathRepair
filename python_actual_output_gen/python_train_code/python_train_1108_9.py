a,b = list(map(int,input().split()))
count = 0
for i in range(100):
    if a>b:
        print(count)
        break
    else:
        a+=3*a
        b+=2*b
        count+=1