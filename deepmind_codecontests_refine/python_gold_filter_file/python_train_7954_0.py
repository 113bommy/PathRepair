s=input().strip()
n=len(s)
z=s.index("^")
a=[0]*n
for i in range(n):
    if 48<=ord(s[i])<=57:
        a[i]=int(s[i])*abs(z-i)
for i in range(1,n):
    a[i]=a[i]+a[i-1]
if a[z]==a[-1]-a[z]:
    print("balance")
elif a[z]>a[-1]-a[z]:
    print("left")
else:
    print("right")