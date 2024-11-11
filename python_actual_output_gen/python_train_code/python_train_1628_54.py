a,b,c = list(map(int,input().split()))
x = a+b
y = b+c
z = a+c
count = 0 
if(x<c):
    count += c-x+1
elif(y<a):
    count += a-y+1
elif(z<b):
    count += b-z+1
print(count)
