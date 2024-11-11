n=list(input())
p=list(input())
t=len(n)
count = 0
for i in range(t-1):
    if (n[i] == '0' and p[i] == '0' and p[i+1]=='0') :
        count =count+1
        n[i]='X'
        p[i]='X'
        p[i+1]='X'
    elif (n[i] == '0' and p[i] == '0' and  n[i+1]=='0') :
        count =count+1
        n[i]='X'
        p[i]='X'
        p[i+1]='X'
    elif (n[i] =='0' and n[i+1] =='0' and p[i+1]=='0') :
        count =count+1
        n[i+1]='X'
        n[i]='X'
        p[i+1]='X'
    elif ( p[i] =='0' and n[i+1] =='0' and p[i+1]=='0') :
        count =count+1
        n[i+1]='X'
        p[i]='X'
        p[i+1]='X'
print(count)