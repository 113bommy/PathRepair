n=int(input())
a=list(map(int,input().split()))
b=set(a)
print("YES" if n == len(b) else "NO")
