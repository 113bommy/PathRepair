num_of_steps=int(input())
steps=input().split()
counter_of_ladders=1
kek=[]
for i in range(1,len(steps)):
    if steps[i]==1:
        kek.append(steps[i-1])
        counter_of_ladders+=1
print(counter_of_ladders)
if len(kek)==0:
    print(steps[len(steps)-1])
else:
    print(' '.join([str(i) for i in kek]),steps[len(steps)-1])