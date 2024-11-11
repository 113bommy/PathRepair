t = int(input())
 
def solve(n,k):
    if k%3 != 0:
        return n%3
    else:
        if n%(k+1) == k:
            return 3
        else:
            return n%(k+1)%3
 
for _ in range(t):
    n,k = map(int,input().split())
    if solve(n,k):
        print('Alice')
    else:
        print('Bob')