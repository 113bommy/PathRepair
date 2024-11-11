a,b=map(int,input().split())
print("Possible" if (a+b) % 3 == 0 or a % 3 == 0 and b % 3 == 0 else "Impossible")