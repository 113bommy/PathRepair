n, m = map(int,input().split())
count = 0
x = n*m
while(x>0):
    x-=2
    count+=1
    if (x==1):
        break
print(count)
