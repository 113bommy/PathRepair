n=int(input())
da=list(map(int ,input().split()))
Min=2
Max=2
ju=True
for i in da[::-1]:
    mi=(Min+i-1)//i
    ma=Max//i
    if mi*i>Max or ma*i<Min:
        ju=False
        break
    Min=mi*i
    Max=ma*i+i-1
if ju:
    print(Max,Min)
else:
    print(-1)