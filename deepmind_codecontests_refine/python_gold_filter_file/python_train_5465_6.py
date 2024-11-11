N,S,Q = map(int, input().split(" "))

counter=1
while True:
    x = round(S/(1 - (Q - 1)/Q),9)
    if x >= N:
        break
    S = x
    counter+=1
print(counter)
