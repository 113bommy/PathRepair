a = list(map(int, input().split()))
b = list(map(int, input().split()))
k = 1
t = []
if len(b) > 1:
    
    for j in range(len(b) - 1):
        if b[j] != b[j + 1]:
            k = k + 1
            t.append(k)
        elif b[j] == b[j + 1]:
            t.append(k)
            k = 1
            print(max(t))
else:
    print(len(b))
