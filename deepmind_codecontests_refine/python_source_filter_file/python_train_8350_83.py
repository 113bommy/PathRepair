t=int(input())
def hour(h,k):
    count=1440-(24-h)*60-k
    return count
for i in range(t):
    h,k=map(int,input().split())
    print(hour(h,k))