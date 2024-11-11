n = int(input())
h=[]
w =[]
w_sum =0 
max1 = -111
for i in range(n):  
    t2,t1 = map(int,input().split())
    h.append(t1)
    w.append(t2)
    w_sum+=t2
    if(t1 > max1):
        max1= t1
temp = -100
for i in range(n):
    sum1 = 0
    sum2 = max1
    sum1 = w_sum -w[i]
    if(sum2 > h[i]):
        print(sum1*sum2 ,end = " ")
    else:
        for j in range(n):
            if(j!=i):
                if(temp < h[j]):
                    temp = h[j]
                if(temp == max1):
                    break
        print(temp*sum1,end= " ")
