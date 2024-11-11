ans=[]
for _ in " "*int(input()) :
 n=int(input())
 arr=list(map(int,input().split()))
 h=0
 alice_temp=0
 bob_temp=0
 i=[0]
 alice,bob,k=0,0,0
 
 while i :
    #print(len(arr))
    
    if len(arr)!=0 :
      if h==0 :
       if alice_temp<=bob_temp :
        alice+=arr[0]
        #print(alice)
        alice_temp+=arr[0]
        arr.pop(0)
        if len(arr)==0:
              k+1
              bob_temp=0
       else :
          bob_temp=0
          #print("alice")
          #print(alice)
          h=1
          k+=1
      else :
        if bob_temp<=alice_temp :
            bob+=arr[-1]
            #print("bob",bob)
            bob_temp+=arr[-1]
            arr.pop()
            if len(arr)==0 :
                  k+=1
                  #print("bob empty")
                  alice_temp=0
        else :
             #print(bob_temp,alice)
             #if bob_temp>alice_temp :
             alice_temp=0
             h=0
             k+=1
             #print('k')
             #print(bob)
        
        
        
    else :
        #print(k,alice,bob)
        ans.append((k,alice,bob))        
        break
for i in ans :
      print(*i)
