n = int(input())
m = list(map(int,input().split()))
al = 0
for i in range(0,2*n-1,2):
    if m[i]!=m[i+1]:
        print('-',m[i])
        di = 0
        di1 = 0
        for j in range(i+2,2*n):
            if m[j]==m[i]:
                di = j-i-1
            elif m[j]==m[i+1]:
                di1 = j-i
                # if i!=0: di1+=1
            print('--',m[j],di,di1)
        al += min(di,di1)
        if di < di1:
            m = m[:i+1] + [m[di+i+1]] + [m[i+1]] + m[i+2:di+i+1] + m[di+i+2:]
        else:
            # if i!=0:di1-=1
            m = m[:i] + [m[di1+i]] + [m[i+1]] + [m[i]] + m[i+2:di1+i] + m[di1+i+1:]
        print(m)
print(al)
        
