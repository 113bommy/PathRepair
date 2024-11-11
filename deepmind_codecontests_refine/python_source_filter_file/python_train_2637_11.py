n = input() 
line = input().split()

data={}
for item in line:
    data[item]=data.get(item,0)+1
    
data['4']=data.get('4',0)
data['3']=data.get('37',0)
data['2']=data.get('2',0)
data['1']=data.get('1',0)
    
taxi_num=data['4']+data['3']
    
if data['3']>=data['1']:
    taxi_num=taxi_num +(data['2']+1)//2

if data['3']<data['1']:
    data['1']=data['1']-data['3']
    data['1']=data['1']-2*(data['2']%2)
    taxi_num=taxi_num +(data['2']+1)//2 +(data['1']+3)//4
    
print(taxi_num)