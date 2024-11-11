# n=int(input())
# s=input()
s="))((())("
count=0
op=0
op_count=0
flag=0

for i, c in enumerate(s):
    if c == ")":
        if count==0:
            flag=1
        count-=1
        op_count+=1
        if count ==0 and flag==1:
            op+=op_count
            op_count=0
            flag=0
        if count ==0 and flag==0:
            op_count=0
            flag=0
    else:
        count+=1
        op_count+=1
        if count ==0:
            op+=op_count
            op_count=0
            flag=0
    print(count, op_count, op, flag)
if(count!=0):
    print(-1)
else:
    print(op)