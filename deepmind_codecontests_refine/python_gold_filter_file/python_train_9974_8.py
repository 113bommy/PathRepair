from fractions import gcd
N=int(input())
A=list(map(int,input().split()))
left,right=[0],[0]
[(left.append(gcd(left[i],A[i])),right.append(gcd(right[i],A[N-i-1]))) for i in range(N-1)]
right.reverse()
print(max([gcd(a,b) for a,b in zip(left,right)]))