a,b= list(map(int, input().split()))
print("Possible" if a%3 == 0 or a%3 == 0 or (a+b)%3 == 0 else "Impossible")
