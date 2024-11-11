s1=list(input())
s2=list(input())
s3=s1[:]
s4=s2[:]
s3.sort()
s4.sort()
k=0
if s3!=s4 or len(s3)!=len(s4):
    print("NO")
else:
    for i in range(len(s1)):
        if s1[i]!=s2[i]:
            k=k+1
    if k==2:
        print("YES")
    else:
        print("NO")