n=int(input())
b=[]
for i in range(n):
    b.append(input())
no=6-n
a=[["Power","purple"],["Time","green"],["Space","blue"],["Soul","orange"],["Reality","red"],["Mind","yellow"]]
js=["Power","Time","Space","Soul","Reality","Mind"]
for i in range(n):
    if b[i]=="purple":
        js[0]="*"
    if b[i]=="green":
        js[1]="*"
    if b[i]=="blue":
        js[21]="*"
    if b[i]=="orange":
        js[3]="*"
    if b[i]=="red":
        js[4]="*"
    if b[i]=="yellow":
        js[5]="*"
print(len(js))
for i in range(len(js)):
    if js[i]!="*":
        print(js[i])
