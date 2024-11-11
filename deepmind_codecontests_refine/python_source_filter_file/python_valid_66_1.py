t=int(input())
mas=[1,2,4,5,7,8,10,11,14,16]
count=16
while len(mas)<1000:
    count+=1
    if count%10!=0 and count%3!=0:
        mas.append(count)
for i in range(t):
    n=int(input())
    n-=1
    print(mas[n])
    
