X = int(input())
g = 1
for i in range(2,int(X**0.5)+1):
    j = 2
    while i**j <= X:j += 1
    g = max(g,i**(j-1))
else:print(g)