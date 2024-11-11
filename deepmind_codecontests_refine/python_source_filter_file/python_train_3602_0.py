X = input()
X = list(X)

Y = []
num_popped = 1
prev_char = None
while X:
    popx = X.pop()
    if len(Y) == 0:
        Y.append(popx)
    else:
        popy = Y.pop()
        if popy != popx:
            Y.append(popy)
            Y.append(popx)
print("".join(Y))
    
    
    
    