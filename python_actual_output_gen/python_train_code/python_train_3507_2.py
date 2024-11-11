a = [0,1,2,3,4,5,6,7,8,9]

wa_lis = []
num = 0
def wa(n,k,m):
    global num

    if n == 9 and m == 0 and k == 0:
        num += 1
    if n == 10:
        return
    return wa(n + 1,k - a[n],m - 1) or wa(n+1,k,m)

while True:
   
    n,s = map(int,input().split())
    if [n,s] == [0,0]:
        break
    wa(0,s,n)
    print(num)
    num = 0