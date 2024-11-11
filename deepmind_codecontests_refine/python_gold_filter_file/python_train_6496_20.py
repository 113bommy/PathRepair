n,m=map(int,input().split())
house=list(map(int,input().split()))
distance=0
last_location=1
for i in house:
    if i<last_location:
        distance+=n+i-last_location
        last_location=i
    else:
        distance+=i-last_location
        last_location=i
print (distance)