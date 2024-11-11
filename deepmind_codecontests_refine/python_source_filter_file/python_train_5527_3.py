n, m=map(int, input().split())
program=[0]+[int(x) for x in input().split()]+[m]
ori_off=0
ori_on=0
final=0
for i in range(1,n+2):
    if i%2==0:
        ori_off+=(program[i]-program[i-1])
    else:
        ori_on+=(program[i]-program[i-1])
maximum=ori_on
for i in range(1,n+1,2):
    final+=(program[i]-program[i-1])
    if program[i]-program[i-1]>1 or program[i+1]-program[i]>1:
        maximum=max(maximum,final-1+ori_off)
        ori_off-=(program[i+1]-program[i])
print(maximum)