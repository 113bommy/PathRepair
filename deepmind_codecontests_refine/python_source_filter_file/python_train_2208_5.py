for _ in range(int(input())):
    lis = list(input())+['#']+['#']
    n = len(lis)
    i=2
    aa=[]
    an=0
    while i<n:
        ch=lis[i-2]+lis[i-1]+lis[i]
        if ch=='one':
            an+=1
            aa.append(i)
        elif ch=='two':
            c=0
            j=i
            print(i)
            while i<n and lis[i]=='o':
                i+=1
                c+=1
            if lis[i]+lis[i+1]=='ne' and c==1:
                aa.append(j+1)
                lis[j]='#'
            else:
                aa.append(j)
                lis[j-1]='#'
            an+=1
        i+=1    
    print(an)
    print(*aa)                
                


