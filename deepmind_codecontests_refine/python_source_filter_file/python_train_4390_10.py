sie = [1]*(10**6 + 5)
sie[0] = 0
sie[1] = 0
for i in range(2, 10**3 + 10):
    if sie[i]:
        for j in range(i*i, 10**6 + 5, i):
            sie[j] = 0


def gen(x):
    ans = []
    for i in range(1, x+2):
        if x%i==0:
            ans.append(i)
    ans  = list(set(ans))
    ans.remove(1)
    ans.remove(x)
    return ans

T = int(input())
for t in range(T):
    n = int(input())
    A = [int(i) for i in input().split()]
    if n==1 and sie[A[0]]:
        print(A[0]*A[0])
        continue
    elif n==1:
        print(-1)
        continue
    
    A.sort()

    ans = A[0]*A[-1]

    from collections import defaultdict as dd
    
    hsh = dd(int)
    for i in range(n):
        if i <= n-i-1:
            hsh[A[i]*A[n-i-1]] = 1

    if len(hsh.keys()) > 1:
        print(-1)
    else:
        op = []
        for i in range(2, int(ans**0.5) + 5):
            if ans % i ==0:
                op.append(i)
                op.append(ans//i)
        op = sorted(list(set(op)))
        #print(op, A)
        if op != A:
            print(-1)
            continue
        
        print(ans)
        continue
        

