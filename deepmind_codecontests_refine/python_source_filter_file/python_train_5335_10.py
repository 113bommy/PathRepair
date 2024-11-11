t=int(input())
for _ in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    a=arr.pop(0)
    b=0
    ali=a
    bob=0
    c=1
    count=1
    #print(ali)
    while arr:
        if c==1:
            #print("bob")
            b=0
            while b<=a and arr:
                b+=arr.pop()
            if b>a:
                c=0
                bob+=b
                count+=1
                #print(arr,b,bob)
            if arr==[] and b<a :
                bob+=b
                count+=1
            #print("bob",bob,arr)
                
        else:
            #print("alice",ali)
            a=0
            while b>=a  and arr:
                a+=arr.pop(0)
            #print(a,b)
            if a>b:
                c=1
                ali+=a
                count+=1
                #print("aliii",arr,a,ali)
            if arr==[] and a<b:
                ali+=a
                count+=1
            #print("al",ali,arr)
    print(count,ali,bob)
                
                
                
                
        
        
        
        
             
