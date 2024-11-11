def score(t,w,x):
    return int(max(0.3*x,(1-t/250)*x-50*w));

T=list(map(int,input().split()))
W=list(map(int,input().split()))
s = 0
h, f = list(map(int,input().split()))
s += h*100
s -= f*50
s += sum(score(T[i], W[i], 500*i+500) for i in range(5))
print(s)
