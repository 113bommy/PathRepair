T = int(input())
r = 1

prime = [2]

for i in range(3,4*10**3,2):
    flag = False
    if i%2==0: continue 
    for j in range(3,int(i**0.5)+1,2):
        if i%j==0: 
            flag = True 
            break
    if not flag:  prime.append(i)


#print(prime)


def primefactor(num):

    index = 0
    output = []

    while num>=prime[index]**2:

        times = 0
        while num%prime[index]==0:
            num = num // prime[index]
            times += 1
        if times&1:  output.append(prime[index])
        index += 1 

    if num>1: output.append(num)


    return tuple(output)





while r<=T:
    n,k = map(int,input().split())
    

    arr = list(map(int,input().split()))

#    arr = [5*i+1 for i in range(n)]
#    print(arr)


    ans = 1
    fact = {}
    for i in range(n):
#        if i%100==0: print(i)
        num = arr[i]
        factnum = primefactor(num)
#        print(num,factnum)
        if factnum in fact:
            fact = {factnum:1}
            ans += 1    
        
        else:
            fact[factnum] = 1
 

       

    
        
    print(ans)



    r += 1
