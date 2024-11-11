n=int(input())
s='codeforces'
l=[1]*10
pro=1
ss=""
while(pro<n):
    for i in range(10):
        x=l[i]
        l[i]+=1
        pro=(pro*l[i])//x
        if(pro>n):
            break
for i in range(10):
    ss+=s[i]*l[i]
print(ss)
