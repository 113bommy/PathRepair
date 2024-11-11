N,S,Q = map(int, input().split(" "))

counter=1
while True:
    x = S/(1 - (Q - 1)/Q)
    if x >= N:
        break
    S = x
    counter+=1
print(counter)
