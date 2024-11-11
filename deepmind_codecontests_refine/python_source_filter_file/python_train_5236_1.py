import bisect
A=[]
v=2
mv=20
for i in range(mv+1):
    v=v*2
    A.append(v)
    
#print(A)
def main():
    T=int(input())
    for _ in range(T):
        k=int(input())
        n=0
        ans=[]
        if (k%2!=0):
            print(-1)
        else:
            while(k>0 and n<=2000):
                n=n+1
                ans.append(1)
                k=k-2
                for i in range(mv+1):
                    if (A[i]>k or n>2000):
                        break
                    n=n+1
                    k=k-A[i]
                    ans.append(0)

            if (n>=2000):
                print(-1)
            else:
                print(n)
                print(*ans)
                
main()
