s=input()
n1=[int(i) for i in s.split()]
n=n1[0]
t=n1[1]
s=input()
n2=[0]+[int(i) for i in s.split()]
i=1
found=0
while i<=n:
        if i==t:
                found=1
                break
        elif i>t:
                break
        else:
                i+=n2[i]
if found==0:
        print("NO")
else:
        print("YES")
