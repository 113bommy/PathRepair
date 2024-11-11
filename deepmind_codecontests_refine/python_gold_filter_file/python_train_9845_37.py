n=input()
n=int(n)
s=input()
a=0
d=0
for i in range(0,n):
    if(s[i]=='A'):
        a=a+1;
    elif(s[i]=='D'):
        d=d+1;
if(a>d):
    print("Anton")
elif(d>a):
    print("Danik")
elif(a==d):
    print("Friendship")