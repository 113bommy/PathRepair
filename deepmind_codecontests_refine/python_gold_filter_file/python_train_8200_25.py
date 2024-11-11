n=int(input())
A=list(map(int,input().split()))



print("YES" if len(set(A))==len(A) else "NO")