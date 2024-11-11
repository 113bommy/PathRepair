l=list(input())
n=len(l)
s=1
for i in range(n):
    if i<n-1:  
        if  l[i]==l[i+1]:
            s+=1
            if s>=7:
                print('YES')
                break
        else:
            s=1
if s<7:
    print('NO')