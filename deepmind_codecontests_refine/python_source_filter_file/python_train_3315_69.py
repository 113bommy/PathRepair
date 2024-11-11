a,b=map(int,input().split())
print("Possible" if any(a%3==0,b%3==0,(a+b)%3==0) else "Impossible")