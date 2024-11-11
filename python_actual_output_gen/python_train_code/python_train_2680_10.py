s1=input()
s2=input()
s3=input()
f=0
if s2[0]==s2[-1]:
    for i in range(3):
        if s1[i]==s3[len(s3)-i-1]:
            f=1
            break
    if f==1:
        print("YES")
    else:
        print("NO")
else:
    print('NO')