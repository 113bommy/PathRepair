x1=str(input()).split()
strr2=list(map(int,str(input()).split()))
arr=[0]*(int(x1[0]))
s=set([strr2[-1]])

for i in range(1,int(x1[0])+1):
    s.add(strr2[-i])
    arr[-i] = len(s)
for i in range(int(x1[1])):
    print(arr[int(input())-1])


