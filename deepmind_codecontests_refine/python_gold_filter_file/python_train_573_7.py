a,b,c=map(int,input().split())
for i in range(c//a+1):
    if (c-a*i)%b==0: print("Yes"); break
else: print("No")