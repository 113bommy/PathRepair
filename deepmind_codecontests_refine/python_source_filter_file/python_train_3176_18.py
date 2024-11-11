n , t = input().split()
n , t  = int(n) , int(t)
st = '1'
for i in range(n-1):
    st+='0'
st = int(st)

m = True
for i in range(st , st*2):
    if i%t == 0:
        print(i)
        m = False
        break
if m:print(-1)
