a,b=map(int,input().split())
x=0
for i in range(a,b+1):
 if str(i)==str(i)[::-1]:x+=1
print(x)