n,a,b,c=map(int,input().split())
s=[]
for i in range(n):
    s.append(input())
s.append('EOF')

ans=[]
 
flag=True
 
for i in range(n):
    if s[i]=='AB':
        if a==0 and b==0:
            flag=False
            break
        if a==0 or (b!=0 and a==1 and s[i+1]=='AC'):
            ans.append('A')
            a+=1
            b-=1
        else:
            ans.append('B')
            a-=1
            b+=1
    elif s[i]=='AC':
        if a==0 and c==0:
            flag=False
            break
        if a==0 or (c!=0 and a==1 and s[i+1]=='AB'):
            ans.append('A')
            a+=1
            c-=1
        else:
            ans.append('C')
            a-=1
            c+=1
    else:
        if c==0 and b==0:
            flag=False
            break
        if c==0 or (b!=0 and c==1 and s[i+1]=='AC'):
            ans.append('C')
            c+=1
            b-=1
        else:
            ans.append('B')
            c-=1
            b+=1

if flag:
    print("Yes")
    for i in ans:
        print(i)
else:
    print("No")