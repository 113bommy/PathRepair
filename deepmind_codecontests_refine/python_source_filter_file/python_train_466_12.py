m = list(map(int, input().split()))
w = list(map(int, input().split()))
hs, hw = map(int,input().split())
x = [500,1000,1500,2000,2500]
score= 100*hs - 50*hw
for i in range(5):
    a = 0.3 * x[i]
    b = x[i] - (50*w[i]) - (m[i]*x[i]//250)
    score+= max(a,b)
print(score)