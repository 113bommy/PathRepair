a,b,c=map(int,input().split())
print("YES" if 100*a+10*b+c%4==0 else "NO")