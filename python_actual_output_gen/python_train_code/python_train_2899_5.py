n=int(input())
s=input()
s1=0
s2=0
c1=0
c2=0
for i in range(n//2):
    if s[i]!="?":
        s1+=int(s[i])
    else:
        c1+=1
    if s[-i-1]!="?":
        s2+=int(s[-i-1])
    else:
        c2+=1
        
if c1>c2:
    c1-=c2
    print(c1)
    if s1 + 9*(c1//2)>s2 or s1 + 9*(c1//2)<s2:
        print("Monocarp")
    else:
        print("Bicarp")
else:
    c2-=c1
    if s2 + 9*(c2//2)>s1 or s2 + 9*(c2//2)<s1:
        print("Monocarp")
    else:
        print("Bicarp")
    