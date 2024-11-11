def cal(s,n):
    sum=0
    for i in range(0,len(s)):
        sum+=int(s[i])

    if sum>9:
        n=n+1
        return cal(str(sum),n)
    else:
        return n


n=1
s=input()
if len(s)==1:
    print("0")
else:
    print(cal(s,n))
    
