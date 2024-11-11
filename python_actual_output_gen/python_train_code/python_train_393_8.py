k=int(input())
n=input()
s_n=0
for i in n:
    s_n+=int(i)
if s_n>k:
    print(0)
else:
    n=sorted(n)

    change=0
    amader_lagbe=k-s_n
    for i,char in enumerate(n):
        now_sum=9-int(char)
        amader_lagbe-=now_sum
        if amader_lagbe<=0:
            print(change+1)
            exit()
        change+=1
