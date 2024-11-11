# You have to be at your strongest when you're feeling at your weakest. Unknown

for _ in range(int(input())):
    n=int(input());a=list(map(int,input().split()))
    print("T" if sum(a[:-1])<a[-1] else "HTL"[sum(a)%2::2] )
