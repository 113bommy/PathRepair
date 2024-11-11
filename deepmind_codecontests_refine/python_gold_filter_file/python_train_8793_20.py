import sys
numbers=sys.stdin.readline().split(" ")
numbers = list(map(int, numbers))
p=numbers[0]
q=numbers[1]

count2=0
count1=0

while(q>p):
    
    if(q%2!=0):
        q=(q+1)/2
        count2=count2+1
        count1=count1+1

    elif(q%2==0):
        q=q/2
        count2=count2+1

diff=p-q
ans=count2+count1+diff
print(int(ans))
    

