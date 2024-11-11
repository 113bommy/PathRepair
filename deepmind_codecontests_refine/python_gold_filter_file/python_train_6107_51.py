s= input()
s=list(s)
n = len(s)
s1 = ['1','1','1','1','1','1','1']
s2 = ['0','0','0','0','0','0','0']
flag = True
for i in range(len(s)-6):
    s3=s[i:i+7]
    if(s3==s1 or s3 ==s2):
        print("YES")
        flag = False
        break

if(flag):
    print("NO")



