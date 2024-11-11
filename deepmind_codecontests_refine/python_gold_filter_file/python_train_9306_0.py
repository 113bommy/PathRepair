n, d = [int(i) for i in input().split()]
S = sorted([int(i) for i in input().split()])
k = 0
for i in range(n):
    for j in range(i+1, n):
        if(S[j]-S[i]<=d):
            k += 1
        else:
            break
print(k*2)