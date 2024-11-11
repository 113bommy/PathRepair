k, a, b = map(int, input().split())
x=k+1
y=0
if b>a:
    c=b-a
    k=k-a-1
    y=c*(k//2-1)+b+(k%2)
print(max(x.y))