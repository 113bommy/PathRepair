n=input()
a=list(map(int,input().split()))
print("No" if sum(a)<=2*max(a) else "Yes")
