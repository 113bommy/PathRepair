a=input()
s=input()
t=len(s)
i=0
while(t-3>0):
    print(int(s[i:i+2]),end ="-")
    i=i+2
    t=t-2
print(s[i:])