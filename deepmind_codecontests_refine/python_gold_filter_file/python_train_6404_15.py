x=input()
y=input()
idx=0
k=""
for i in range(len (x)):
        if x[idx]==y[idx]:
                k=k+"0"
                idx=idx+1
        elif x[idx]!=y[idx]:
                k=k+"1"
                idx=idx+1
print(k)
