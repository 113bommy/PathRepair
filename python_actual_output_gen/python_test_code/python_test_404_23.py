t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    j=1
    s=0
    while s<k:
        s+=j
        i+=1
    print("a"*(n-j)+ "b" + "a" *(s-k)+ 'b' +'a'*(k+j-2-s))