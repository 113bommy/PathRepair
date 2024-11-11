w=list(map(int,input().split()))
b1=list(map(int,input().split()))
b2=list(map(int,input().split()))
def find(a,b):
    return max(a[0],b[0]),max(a[1],b[1]),min(a[2],b[2]),min(a[3],b[3])
def area(a):
    return max(a[2]-a[0],0)*max(a[3]-a[1],0)
if area(find(w,b1))+area(find(w,b2))-area(find(b1,b2))==area(w):
    print("NO")
else:
    print('YES')
