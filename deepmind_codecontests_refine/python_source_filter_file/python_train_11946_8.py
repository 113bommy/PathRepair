'''n = input()
if("BAC" in n or "ABC" in n or "CAB" in n  or "ACB" in n or "BCA" in n or "CBA" in n):print("YES")
else : print("NO")'''

n , m = map(int,input().split())
st = input()
lr = n - m
for i in range(lr):
    if(i+m<n and st [i] != st[i+m] )or(i+m<n and st[i]=='.' and st[i+m]=='.'):
        if(st[i]=='.' and st[i+m]=='.'):
            for j in range(n):
                if(j==i):print(0,end="")
                elif j == (i+m) : print(1,end="")
                elif(st[j]=='.'):print(0,end="")
                else:print(st[j],end="")
        elif st[i]!='.' and st[i+m]!='.':
            for j in range(n):
                if(st[i]=='.'):print(0,end="")
                else:print(st[j],end="")
        else:
            st=list(st)
            if(st[i]!='.' and st[i]=='1'):
                st[i+m]='0'
            elif (st[i]!='.' and st[i]=='0'):
                st[i+m]='1'
            elif st[i+m]=='0':
                st[i]='1'
            else : st[i]='0'
            for j in range(n):
                if(st[j]=='.'):print(0,end="")
                else : print(st[j],end="")
        print()
        exit()
print("NO")