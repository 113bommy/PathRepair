n,a=map(int,input().split())
angle=180*(n-2)/n/(n-2)
Max,Ma=0,180
for i in range(n-2):
    if abs(a-angle*(i+1))<Ma:
        Max,Ma=i+1,abs(a-angle*(i+1))
print(2,1,2+i+1)
