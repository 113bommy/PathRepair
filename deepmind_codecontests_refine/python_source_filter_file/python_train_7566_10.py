n=int(input())
r=input()
i=1
while i<=n:
    if n%i==0:
     s=r[0:i]
     s1=s[::-1]   
     r=s1+r[i:n]
    i+=1
    print(r)