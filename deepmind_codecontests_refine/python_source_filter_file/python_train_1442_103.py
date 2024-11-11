X, A, B = map(int, input().split())
print(["No", "Yes"][(A*10+B)%4==0])