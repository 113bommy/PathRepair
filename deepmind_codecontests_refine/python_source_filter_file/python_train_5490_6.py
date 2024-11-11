n=int(input())
s=[]
for i in range(n):
    s.append(str(input()))
s=sorted(s,key=lambda x:len(x))
print(s)
flag=0
for i in range(len(s)-1):
    if s[i] not in s[i+1]:
        flag=1
        break
if(flag==1):
    print("NO")
else:
    print("YES")
    for i in s:
        print(i)