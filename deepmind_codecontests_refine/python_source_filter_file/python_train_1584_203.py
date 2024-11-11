a=int(input())
q=4

def n(w):
    n = w
    counter = 0
    for i in range(1, n + 1):
        if n % i == 0:
            counter += 1
    return 1 if counter == 2 else 2
while True:
    if n(q+a)==2 and n(q)==2:
        print(q,q+a)
        break
    else:
        q+=1