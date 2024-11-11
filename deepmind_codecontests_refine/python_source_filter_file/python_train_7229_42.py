n, m=map(int, input().split())
i=0
while n!=0 and m!=0:
    n-=1
    m-=1
    i+=1
if i%2:
    print("Malvika")
else:
    print("Akshat")
