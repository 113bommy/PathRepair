m = int(input())
a = [0] * 200001
for i in range(1,200001):
    n = 0
    x = i
    while x % 5 == 0:
        x//=5
        n+=1
    a[i] = a[i-1]+n
    
good = 0
g = []
for i in range(200001): 
    if a[i] == m:
        good += 1
        g.append(i)
print(good)
for elem in g:
    print(elem, end = ' ')