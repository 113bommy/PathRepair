# B - Two Arrays
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
sum_a=sum(a)
sum_b=sum(b)
a_cnt,b_cnt=0,0

for aa,bb in zip(a,b):
    if aa>bb:
        a_cnt+=aa-bb
    elif aa<bb:
        b_cnt+=((bb-aa)//2)*2

print('Yes') if a_cnt<=b_cnt else print('No')