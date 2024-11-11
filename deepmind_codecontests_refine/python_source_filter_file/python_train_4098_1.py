A = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','_','1','2','3','4','5','6','7','8','9','0'}
s = input()
k=0
i = s.find('@')
s1 = s[:i]
j = s.find('/')
if j!=-1:
    s2 = s[i+1:j]
else:
    s2=s[i+1:]
z=0
s3=''
if j!=-1:
    s3 = s[j:]
cnt=0
if len(s1)<=16 and len(s1)>=1:
    for i in range(len(s1)):
        if s1[i] not in A:
            k+=1
else:
    k+=1
p = 0
if len(s2)<=32 and len(s2)>=1:
    for i in range(len(s2)):
        if s2[i] not in A and s2[i]!='.':
            k+=1
        else:
            if s2[i]!='.':
                p+=1
                if p>16:
                    k+=1
            else:
                if p!=0:
                    p=0
                else:
                    k+=1
    if s2[-1]=='.':
        k+=1


else:
    k+=1
if len(s3)<=16 and len(s3)>=2 or len(s3)==0:
    for i in range(1,len(s3)):
        if s3[i] not in A:
            k+=1
else:
    k+=1
if k==0:
    print('YES')
else:
    print('NO')