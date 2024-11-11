

def solve(s):
    ans=""
    n=len(s)
    for i in range(0,n-2,2):
        ans=ans+s[i]+s[i+1]+'-'
    return ans+s[n-2]+s[n-1];

n=int(input())
s=input()
if(n%2):
    print(s[:-1])
    print(solve(s[:-1])+s[n-1])
else:
    print(solve(s))
