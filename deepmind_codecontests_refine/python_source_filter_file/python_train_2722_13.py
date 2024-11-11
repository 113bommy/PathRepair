n=int(input())
lst=[]
f=0
for i in range(n):
    #ls = list(map(int, input().strip().split(' ')))
    ls=input()
    ls=list(ls)
    lst.append(ls)
    
i=0
while(i<n-1):
    
    if '.' in lst[i]:
        l=lst[i].index('.')
        #print(l)
        if l==0 or l==n-1:
            f=1
            print('NO')
            break
        else:
            if i<n-2:
                if lst[i+1][l-1]!='.' or lst[i+1][l]!='.' or lst[i+1][l+1]!='.' or lst[i+2][l]!='.':
                    f=1
                    print('NO')
                    break
                else:
                    lst[i][l]='#'
                    lst[i+1][l-1]='#'
                    lst[i+1][l]='#'
                    lst[i+1][l+1]='#'
                    lst[i+2][l]='#'
            else:
                f=1
                print('NO')
                break
    
            
    if '.' not in lst[i]:
        i+=1
    #print(lst)
        
if f==0:
    print('YES')
            
    
    
    