def process(data,n,delay_time):
    time=[]
    for i in range(n):
        time.append(60*data[i][0]+data[i][1])
    if time[0]>=delay_time+1:
        return 0
    else:
        for i in range(1, n):
            if time[i]-time[i-1]>=2*delay_time+2:
                return(time[i-1]+delay_time+1)
            
    return time[-1]+delay_time+1
    

sentinel=''
lines=[]
line1=list(map(int,input().split()))
n=line1[0]
delay_time=line1[1]
data=[[0,0] for cols in range(n)]
for i in range(n):
    temp=list(map(int,input().split()))
    data[i][0]=temp[0]
    data[i][1]=temp[1]
    i+=1

land_time=process(data,n,delay_time)
print(land_time//60,land_time%60)
