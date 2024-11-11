n,k=map(int,input().split(" "))
st=''
for i in range (97,97+k):
          st+=chr(i)
x=0   
x=n-k
if x==0:
    print(st)
if x>0:
    for i in range (0,x):
        st+=st[i]
print(st)