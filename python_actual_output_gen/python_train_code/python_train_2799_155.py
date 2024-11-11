s=input().split()
for i in range(8):
    s[i]=int(s[i])
a=s[1]*s[2]//s[6]
b=s[3]*s[5]
c=s[5]//s[7]
d=min(a,b,c)
e=d//s[0]
print(int(e))