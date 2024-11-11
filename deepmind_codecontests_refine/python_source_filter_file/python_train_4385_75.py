s=input().split()
x=int(s[0])
y=int(s[1])
z=int(s[2])
t1=int(s[3])
t2=int(s[4])
t3=int(s[5])
if (((abs(x-z))*t2+t3)+(abs(y-x)*t2+t3))>(((abs(y-x))*t1)):
    print("NO")
else:
    print("YES")