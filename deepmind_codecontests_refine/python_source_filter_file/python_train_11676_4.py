n=int(input())
s=str(n)
count=0
if len(s)==1:
    print(9)
else:
    for i in range(len(s)):
        if i==0:
            count+=9
        else:
            count+=9-int(s[i])
print(count+1)
    