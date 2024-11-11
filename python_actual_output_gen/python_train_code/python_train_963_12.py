import sys
n=int(sys.stdin.readline().split()[0])

events=[int(i) for i in sys.stdin.readline().split()]

policeman_count=0
crime_count=0

for event in events:
    if event==-1:
        if policeman_count>0:
            policeman_count-=1
        else:
            crime_count+=1
    elif 10>event>0:
        policeman_count+=event
       
print(crime_count)    
