a=str(input())
x=k=int(0)
y=len(a)
while x<y:
    if a[x]=='a' or a[x]=='e' or a[x]=='i' or a[x]=='o' or a[x]=='u' or a[x]=='0' or a[x]=='2' or a[x]=='4' or a[x]=='6' or a[x]=='8':
        k=k+1
    x=x+1
print(k)