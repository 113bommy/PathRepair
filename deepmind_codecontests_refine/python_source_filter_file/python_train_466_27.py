
m=[int(i) for i in input().split()]
w=[int(i) for i in input().split()]
h=[int(i) for i in input().split()]
mx=0
x=[500,1000,1500,2000,2500]
for i in range(5):
    mx+=max(0.3*x[i],(1-m[i]/250)*x[i]-50*w[i])
print(mx+100*h[0]-50*h[1]) 

