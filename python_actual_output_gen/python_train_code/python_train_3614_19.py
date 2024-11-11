n=int(input())
scores=[]
r=0
for i in range(n):
    a,b,c,d=input().split()
    a,b,c,d=int(a),int(b),int(c),int(d)
    s=a+b+c+d
    scores.append(s)
result=sorted(scores,reverse=True)
for i in range(n-1):
    r+=1;
    if(result[i]==scores[0]):
        print(r)
        break
    


   
    
            

    




