s=input()
n=int(input())
f=0
arr=[]
for i in range(n):
    k=input()
    arr.append(k)
    if k==s:
        f=1
for i in range(n):
    for j in range(2):
        if arr[i][0] == s[1]:
            
            for k in range(n):
                if  arr[k][1]==s[0]:
                        f=1
        elif arr[i][1] == s[0]:
            
            for k in range(n):
                if arr[k][0]==s[1]:
                        f=1

if f==1:
    print("YES")
else:
    print("NO")
    
