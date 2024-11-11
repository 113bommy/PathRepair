import time
t=time.time()+.3
n=int(input())
count=i=0
while count!=n:
    i+=1
    k=i
    while k%5==0:
        count+=1
        k=(k//5)
    if time.time()>=t:
        print(0)
        exit(0)
print(5)
print(i,i+1,i+2,i+3,i+4)