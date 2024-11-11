def f(A):
    ans=(sum(A))//(len(A))
    if ans==int(ans):
        return ans
    else:
        return ans+1
    
    
a=int(input())
for tc in range(a):
    b=input()
    c=list(map(int,input().split()))
    print(f(c))