n=int(input())
if any (n%i==0 for i in [4,7,47,744,477]):
    print("YES")
else:
    print("NO")