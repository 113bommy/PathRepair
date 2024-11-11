X = int(input())
i = int(n**0.5)

while i >= 2:
    if X % i == 0:
        X += 1
        i = int(X**0.5)
    else:
        i -= 1
        
print(X)