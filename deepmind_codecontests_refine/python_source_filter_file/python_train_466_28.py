def g(w,m,x):
    return max(0.3*x,(1-m/250)*x-50*w)


m1,m2,m3,m4,m5=map(int,input().split())
w1,w2,w3,w4,w5=map(int,input().split())
h1,h2=map(int,input().split())
print(g(w1,m1,500)+g(w2,m2,1000)+g(w3,m3,1500)+g(w4,m4,2000)+g(w5,m5,2500)+h1*100-h2*50)