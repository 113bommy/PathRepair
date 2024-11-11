n=int(input())
k=input().split()
sec=[]
elodreip=0
for i in k:
    sec.append(int(i))
    elodreip+=int(i)
sec.sort()
auruk=0
max=sec[-1]
while auruk<elodreip:
    for i in sec:
        auruk+=(max-i)
    if auruk<elodreip:
        auruk=0
        max+=1
print(max)