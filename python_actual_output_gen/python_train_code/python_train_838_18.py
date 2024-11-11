X = int(input())
if 0 <= X%100 <= 5*(X//100):
    print("Yes")
else:
    print("No")
