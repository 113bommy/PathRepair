n=int(input())

a=list(map(int,input().split()))

even=[a[0]]
odd=[0]

odd_end =[0]*(n)

even_end=[a[n-1]]*n
if n==1:
    print(0)
else:

    for i in range(1,n):
        if i%2==0:
            even.append(even[-1]+a[i])
            odd.append(odd[-1])
        else:
            odd.append(odd[-1]+a[i])
            even.append(even[-1])
    l=1
    for i in range(n-2,-1,-1):
        if l%2==0:
            even_end[i]=(a[i]+even_end[i+1])
            odd_end[i]=odd_end[i+1]
        else:
            odd_end[i]=a[i]+odd_end[i+1]
            even_end[i]=even_end[i+1]
        l+=1
    ans = 0
    for i in range(n):
        if n%2==0:
            if i==0:
                if odd_end[1]==even_end[1]:ans+=1
            elif i==n-1:
                if even[n-2]==odd[n-2]:
                    ans+=1
            else:
                if even_end[i+1]+even[i-1]==odd_end[i+1]+odd[i-1]:
                    ans+=1
        else:
            
            
            if i==0:
                if odd_end[1]==even_end[1]:ans+=1
            elif i==n-1:
                if even[n-2]==odd[n-2]:
                    ans+=1
            else:
                if odd_end[i+1]+even[i-1]==even_end[i+1]+odd[i-1]:
                    ans+=1
    print(ans)
        