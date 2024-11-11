n,m = map(int,input().split())
s=input()
h=s
k=s[:m]
s=s[m:]
count=1
result=""
while s.find(k)>=0 and len(s)>m:
    s=s[m:]
    count+=1
check=False
for i in range(min(len(k),len(s))):
    if k[i]!=s[i]:
        check=True
        if s[i]==".":
            mid=k[i]
            dk="s"
        else:
            dk="k"
            mid=s[i]
        t=i
        break
if check==False:
    if s.count(".")==0:
        if m==1:
            result=k.replace(".","0",1)+h[m:]
            result=result.replace(".","1")
            print(result)
        else:
            print("NO")
    else:
        result=k.replace(".","0")+h[m:].replace(".","1")    
        print(result)
else:
    if mid=="0":
        if dk=="s":
            result=h[:m]*count+s.replace(".","1",1)
        else:
            result=k.replace(".","1",1)+h[m:]    
    else:
        if dk=="s":
            result=h[:m]*count+s.replace(".","0",1)
        else:
            result=k.replace(".","0",1)+h[m:]    
    result=result.replace(".","0")
    print(result)
