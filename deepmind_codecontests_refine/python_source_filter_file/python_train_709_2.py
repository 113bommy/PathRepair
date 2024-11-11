N,*A=map(int,open(0).read().split())
x=y=0
for x in A:
    if x%4==0:x+=1
    elif x%2==0:y+=1
print(['No','Yes'][x+y//2>=N//2])