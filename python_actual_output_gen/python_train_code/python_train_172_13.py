m = list(map(int,input().split()))
w = list(map(int,input().split()))
hs,hu = map(int,input().split())
rating = [500,1000,1500,2000,2500]
ans = 0
for i in range(5):
    a = int(0.3*rating[i])
    d =round((1-m[i]/250),2)*rating[i]- 50 * w[i]
    ans+= max(a,d)
ans = ans +hs*100 - hu*50
print(int(ans))