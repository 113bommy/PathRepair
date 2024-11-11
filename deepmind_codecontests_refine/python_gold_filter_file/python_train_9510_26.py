n = int(input())
a = list(map(int, input().split()))
mn,mi = a[0],0
more=False
for i in range(1,n):
    if mn>a[i]:
        mn=a[i]
        mi=i
        more=False
    elif mn==a[i]:
        more=True
print('Still Rozdil' if more else mi+1)