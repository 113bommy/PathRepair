#7/4/19
#390A
#BlueyNeilo

n=int(input())
V, H = [False]*100, [False]*100

for _ in range(n):
    x, y = list(map(int,input().split()))
    V[x-1] = True
    H[y-1] = True
    
print(min(V.count(True), H.count(True)))
