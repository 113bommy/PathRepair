n = int(input())
a = list(map(int, input().split()))
st = [0]*n
for i in range(n):
    st[a[i]-1]=i+1
print(st)