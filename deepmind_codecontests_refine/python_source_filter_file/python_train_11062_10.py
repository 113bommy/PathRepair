
for t in range(int(input())):
    _ = int(input())
    l = list(map(int,input().split()))[::-1]
    
    i = 1
    m = 1
    
    while i<len(l):
        if l[i]-l[i-1]>=0 and m>0:
            i+=1
        elif l[i]-l[i-1]<0 and m>0:
            i+=1
            m=-1
        elif l[i]-l[i-1]<0 and m<0:
            i+=1
        else:
            break
    print(len(l)-i)
    
        
    
    