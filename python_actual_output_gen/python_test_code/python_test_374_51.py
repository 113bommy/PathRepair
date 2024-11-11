n=int(input())
a=input()
all_frq={}
x=[]
y=[]
count1=0
count0=0
for i in a:
    if i in all_frq:
        all_frq[i]+=1
    else:
        all_frq[i]=1
for i in all_frq:
    if "n" not in all_frq:
        count1=0
    else:
        count1=all_frq["n"]
    if "z" not in all_frq:
        count0=0
    else:
        count0=all_frq["z"]
for i in range(0,count1):
    x.append("1")
for i in range(0,count0):
    x.append("0")
w=''.join(x)
print(w)