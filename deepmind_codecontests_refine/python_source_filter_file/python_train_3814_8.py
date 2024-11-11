n=int(input())
x="312831303130313130313031"
b=x[-1:]
y="312931303130313130313031"
c=y[-1:]
ch=b+x
ch1=y+x
a=""
l=list(map(int,input().split()))
for i in range(len(l)):
    a+=str(l[i])
if ((y+y+y).find(a)!=-1 or (x+x+x).find(a)!=-1 or (x+x+y+y).find(a)!=-1 or (y+y+x+x).find(a)!=-1) and a.count("29")<2:
    print("yes")
else:
    print("No")
print(a)
