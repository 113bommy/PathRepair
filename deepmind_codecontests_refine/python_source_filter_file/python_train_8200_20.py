n=int(input())
a=list(map(int,input().split()))
b=set(a)
print("YES" if len(a) == len(b), else "NO")