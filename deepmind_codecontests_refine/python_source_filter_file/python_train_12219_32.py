q=lambda:map(int,input().split())
qi=lambda:int(input())
qs=lambda:input().split()
n=qi()
a=list(q())

x=[sum((a[i] for i in range(0,n,3))),sum((a[i] for i in range(1,n,3))),sum((a[i] for i in range(2,n,3)))]
print(['chest','bicep','back'][x.index(max(x))])