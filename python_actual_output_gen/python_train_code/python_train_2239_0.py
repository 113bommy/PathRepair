test=int(input())
def solve():
    n=int(input())
    arr=[int(i) for i in input().split()]
    ans=0
    for i in range(n):
        if(arr[i]==1):
            ans=(ans+1)%2
        else:
            if(ans==0):
                print("First")
                return 
            else:
                print("Second")
                return
    if(ans==0):
        print("First")
        return 
    else:
        print("Second")
        return
            
        


while test:
    solve()
    test-=1
    