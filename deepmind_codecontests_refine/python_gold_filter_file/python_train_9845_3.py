#code
l=int(input())
n=input()
count_1=0
count_2=0
for i in n:
    if i=='D':
        count_1+=1
    if i=='A':
        count_2+=1
if count_2<count_1:
    print('Danik')
elif count_1<count_2:
    print('Anton')
else:
    print('Friendship')