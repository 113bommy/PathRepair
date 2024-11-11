a,b = map(int,input().split())
if(13<a):
    b=b
elif(a<6):
    b=0
else:
    b=b//2
print(b)