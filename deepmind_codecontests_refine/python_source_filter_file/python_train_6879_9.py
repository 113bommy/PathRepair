d=input().split()
for _ in range(int(input())):
 t,f=[d.index(s) for s in input().split()]
 n={0:(1,2,4,3,1),1:(0,3,5,2,0),2:(0,1,5,4,0),3:(1,0,4,5,1),4:(0,2,5,3,0),5:(1,3,4,2,1)}[int(t)]
 print(n[n.index(int(f))+1]+1)