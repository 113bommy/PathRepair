m = list(map(int,input().split()))
w = list(map(int,input().split()))
hs,hu=map(int,input().split())
lis = [500,1000,1500,2000,2500]
score = 0
for i,j,k in zip(m,w,lis):
    score += max(0.3*k,(1-i/250)*k-50*j)
print(int(score+hs*100-hu*hu))