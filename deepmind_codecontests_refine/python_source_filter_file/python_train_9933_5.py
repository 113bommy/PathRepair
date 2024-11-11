a,b=map(int,input().split())
l=[int(i) for i in input().split()]
n1=b
n2=0
if a==b:
    answer=1
else:
    sum1=0
    while n2<b:
        sum1+=l[n2]
        n2+=1
    ans=[(sum1,1)]
    while n1<a:
        sum1=sum1+l[n1]-l[n1-b]
        ans.append((sum1,n1-1))
        n1+=1

    ans.sort(key=lambda t:t[0])
    answer=ans[0][1]
print(answer)
    
    
    
    
    


    
    

