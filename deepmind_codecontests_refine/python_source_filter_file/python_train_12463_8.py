s1 = list(input())
s2 = list(input())
s1 = ["X"]+s1+["X"]
s2 = ["X"]+s2+["X"]

ans =0
for i in range(1,len(s1)-1):
    if(s1[i] == '0' and s2[i]== '0'):
        if s1[i-1] == '0':
            ans+=1
            s1[i]='X'
            s2[i]='X'
            s1[i-1] = 'X'
        elif s1[i+1] == '0':
            ans+=1
            s1[i]='X'
            s2[i]='X'
            s1[i+1] = 'X'
        elif s2[i-1] == '0':
            ans+=1
            s1[i]='X'
            s2[i]='X'
            s2[i-1] = 'X'
        elif s2[i+1] == '0':
            ans+=1
            s1[i]='X'
            s2[i]='X'
            s2[i+1] = 'X'

print(ans)
        