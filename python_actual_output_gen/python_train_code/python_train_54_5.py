data=[int(x) for x in input().split()]
days=[int(x) for x in input().split()]
profit=0
answer=[]
for i in range (data[0]-1):
    profit=days[i]-days[i+1]
    answer.append(profit)
    profit=0
if max(answer)<=0:
    print(0)
else:
    print(max(answer)-data[1])
