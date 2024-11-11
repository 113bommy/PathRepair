n=input()
a=list(map(int,input().split()))
print("YES" if len(set(a))==len(a) else "NO")