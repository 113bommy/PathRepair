n = int(input())
s=[]
for i in range(n):
    s.append([tuple(map(int, input().split())), 's'])
if n >= 2:
    s[0][1]='l'
    s[-1][1]='r'
    ans=2
    for i in range(1, len(s)-1):
        l = s[i][0][0]-s[i-1][0][0]
        r = s[i+1][0][0]-s[i][0][0]
        if s[i-1][1]=='r':
            l-=s[i-1][0][1]
        print(l, r, s[i][0][1])
        if s[i][0][1] < l:
            s[i][1]='l'
            ans+=1
            #print(i, end=' ')
        elif s[i][0][1]<r:
            s[i][1]='r'
            ans+=1
            #print(i+1, end=' ')
        #print()
    #print(s)
    print(ans)
else:
    print(1)
#print(s)