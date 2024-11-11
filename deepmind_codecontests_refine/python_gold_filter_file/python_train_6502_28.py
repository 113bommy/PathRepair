def solve(A): 
    count = (A*(A+1))//2
    return count
n,m=[int(x) for x in input().split(" ")]
k_max=solve(n-m)
if m==1:
    print(k_max,k_max,sep=" ")
else:
    if(n%m==0):
        k_min=solve((n//m)-1)
        print(m*k_min,k_max,sep=" ")
    else:
        x=solve((n//m)-1)
        y=solve(n//m)
        a=n-(n//m)*m
        print(a*y+(m-a)*x,k_max,sep=" ")

        
    