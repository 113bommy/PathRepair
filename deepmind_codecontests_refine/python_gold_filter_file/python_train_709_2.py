N,*A=map(int,open(0).read().split())
x=y=0
for a in A:
    if a%4==0:x+=1
    elif a%2==0:y+=1
print(['No','Yes'][x+y//2>=N//2])