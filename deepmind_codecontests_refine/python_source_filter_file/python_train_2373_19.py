X=int(input())
print(1 if X%100 <= (X//100)*(X//100) else 0)